#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include "decoder.hpp"
#include "../configuration/utility.hpp"

Decoder::Decoder(Napi::Env &env, Buffer<uint8_t> &data, Object&options) : Worker(env, &options){
    this->source = Source::MEMEORY;
    this->bytesStream = new BytesStream();
    this->bytesStream->dataLength = data.Length();
    this->bytesStream->dataPtr = data.Data();
    this->bytesStream->dataRef = ObjectReference::New(data, 1);
}

Decoder::Decoder(Napi::Env &env, std::string filepath,Object&options, Function &callback) : Worker(env, callback, &options){
    this->source = Source::FILE;
    this->fileStream = new FileStream();
    this->fileStream->file = nullptr;
    this->fileStream->filePath = filepath;
}

Decoder::Decoder(Napi::Env &env, Buffer<uint8_t> &data,Object&options,  Function &callback) : Worker(env, callback, &options) {
    this->source = Source::MEMEORY;
    this->bytesStream = new BytesStream();
    this->bytesStream->dataLength = data.Length();
    this->bytesStream->dataPtr = data.Data();
    this->bytesStream->dataRef = ObjectReference::New(data, 1);
}

Decoder::Decoder(Napi::Env &env, std::string filepath, Object&options) : Worker(env, &options){
    // std::cout << "Decoder() 1" << std::endl;  
    this->source = Source::FILE;
    this->fileStream = new FileStream();
    this->fileStream->file = nullptr;
    this->fileStream->filePath = filepath;
}

Decoder::~Decoder() 
{
    // std::cout << "~Decoder()" << std::endl;  
}


void Decoder::AddValueToJSONField(const fit::FieldBase &field, const fit::Profile::MESG_INDEX index, JSON *jsonMesg)
{
    JSON jsonField = {};
    /// if the user choosed to have all the properties int the JSON, we prepare here.
    if( this->options.rawValues ) 
    {
        jsonField = {
            {"num", field.GetNum()},
            {"scale", field.GetScale()},
            {"offset", field.GetOffset()},
            {"count", field.GetNumValues()}
        }; 
    }
    std::string units = field.GetUnits();
    /// check if field 'unit' is empty. if so, we will skip
    if( !units.empty() )
        jsonField["units"] = units;
    size_t len = (FIT_UINT8)field.GetNumValues();
    /// check if field is hex buffer
    if ( field.GetNumValues() > 1 && field.GetType() != FIT_BASE_TYPE_STRING )
    {
        size_t len = (FIT_UINT8)field.GetNumValues();
        std::vector<unsigned char> byteArray;
        for (FIT_UINT8 i = 0; i < len; i++)
            byteArray.push_back(static_cast<unsigned char>(field.GetUINT8Value(i)));
        /// we convert the byte array into an hex string
        std::string std_string = Utility::toHexString(byteArray);
        jsonField["value"] = std_string;
        jsonMesg->emplace(field.GetName(), jsonField);
    }
    else
    {
        for (FIT_UINT8 i = 0; i < len; i++)
        {
            switch (field.GetType())
            {
                case FIT_BASE_TYPE_BYTE:
                case FIT_BASE_TYPE_UINT8:
                case FIT_BASE_TYPE_ENUM:
                case FIT_BASE_TYPE_SINT8:
                case FIT_BASE_TYPE_SINT16:
                case FIT_BASE_TYPE_UINT16:
                case FIT_BASE_TYPE_SINT32:
                case FIT_BASE_TYPE_UINT32:
                case FIT_BASE_TYPE_SINT64:
                case FIT_BASE_TYPE_UINT64:
                case FIT_BASE_TYPE_UINT8Z:
                case FIT_BASE_TYPE_UINT16Z:
                case FIT_BASE_TYPE_UINT32Z:
                case FIT_BASE_TYPE_UINT64Z:
                case FIT_BASE_TYPE_FLOAT32:
                case FIT_BASE_TYPE_FLOAT64:
                {
                    /// we compose byte per byte the numerical value
                    jsonField["value"] = field.GetRawValue(i);
                    jsonMesg->emplace(field.GetName(), jsonField);
                    break;
                }   
                case FIT_BASE_TYPE_STRING:
                {
                    /// the field is a string, we concatenate all the character into a std::string
                    std::wstring w_string = field.GetSTRINGValue(i);
                    std::string std_string;
                    for (char c : w_string)
                        std_string += c;
                    
                    jsonField["value"] = std_string;
                    jsonMesg->emplace(field.GetName(), jsonField);
                    break;
                }
                default:
                    break;
            }
        }
    }
}

void Decoder::Compose(JSON *jsonMesg,std::string msgName,int msgNum )
{
    /// check if msgName key is already present in the jsonFile structure
    if ( this->jsonFile.contains(msgName) )
    {
        /// take the jsonObj with the key that is already inside the jsonFile.
        auto jsonObj = this->jsonFile.find(msgName);
        /// if this jsonObj is already an array, we put directly the new jsonMesg inside that.
        if ( jsonObj->contains("msgs") )
            jsonObj->at("msgs").push_back(*jsonMesg);
        /// otherwise we have to create the JSON array
        else
        {
            JSON jsonValues = JSON::array();
            if( this->options.rawValues )
                jsonObj->erase(jsonObj->find("num"));
            jsonValues.push_back(*jsonObj);
            jsonValues.push_back(*jsonMesg);
            this->jsonFile.erase(msgName);
            JSON newData;
            if( this->options.rawValues )
                newData = {{"msgs", jsonValues}, {"num", msgNum}};
            else
                newData = {{"msgs", jsonValues}};
            this->jsonFile.emplace(msgName, newData);
        }
    }
    /// the msgName key doesn't exist. we can insert right away.
    else
    {
        if(this->options.rawValues)
            (*jsonMesg)["num"] = msgNum;
        this->jsonFile.emplace(msgName, *jsonMesg);
    }
}

void Decoder::OnMesg(fit::Mesg &mesg)
{
    int msgNum = mesg.GetNum();
    if(this->SkipMessage(msgNum))
        return;

    JSON jsonMesg = {};
    std::string msgName = mesg.GetName();
    std::string stringNum = std::to_string(msgNum);
    for (FIT_UINT16 i = 0; i < (FIT_UINT16)mesg.GetNumFields(); i++)
    {
        fit::Field *fit_field = mesg.GetFieldByIndex(i);
        // std::cout << "000 messaggio presente: " << field->GetOffset() << field->GetScale() << std::endl;
        this->AddValueToJSONField(*fit_field, (fit::Profile::MESG_INDEX) mesg.GetNum(), &jsonMesg);
    }
    this->Compose(&jsonMesg,msgName, msgNum);
}

void Decoder::Parse(std::istream *stream)
{
    fit::Decode decode;
    try
    {
        if (this->options.skipHeaders)
            decode.SkipHeader();
        if (this->options.force)
            decode.IncompleteStream();
        if (!this->options.skipHeaders && !this->options.force && !decode.IsFIT(*stream))
        {
            /// il file non e' un FIT
            const std::string error = "Not a FIT file";
            Worker::SetCustomError(StatusCode::NOT_FIT_FILE, error);
            this->SetError(error);
            return;
        }
        // std::cout << std::hex << "FINTO 1"  <<  std::endl;
        if (!this->options.skipHeaders && !this->options.force && !decode.CheckIntegrity(*stream))
        {
            /// il FIT non ha passato il controllo di Integrita'
            const std::string error = "Integrity check failed";
            Worker::SetCustomError(StatusCode::CHECK_INTEGRITY_FAILS,error);
            this->SetError(error);
            return;
        }
        fit::MesgBroadcaster mesgBroadcaster;
        mesgBroadcaster.AddListener((fit::MesgListener &)(*this));
        decode.Read(stream, &mesgBroadcaster, &mesgBroadcaster, this);
    }
    catch (const fit::RuntimeException &e)
    {
        /// errore durante il parsing del file. ritorno cio' che ho letto
        const std::string error = "Error decoding stream: " + std::string(e.what());
        Worker::SetCustomError(StatusCode::DECODE_EXCEPTION, error);
        this->SetError(error);
    }
}

void Decoder::Execute()
{
    switch(this->source){
        case Source::FILE:{
            this->fileStream->file = new std::fstream();
            this->fileStream->file->open(this->fileStream->filePath, std::ios::in | std::ios::binary);
            if (!this->fileStream->file->is_open())
            {
                /// impossibilire aprire il file
                const std::string error ="Cannot open file at path:" + this->fileStream->filePath ;//+ e.what();
                Worker::SetCustomError(StatusCode::COULD_NOT_OPEN,error);
                this->SetError(error);
                return;
            }
            this->Parse(this->fileStream->file);
            break;
        }
        case Source::MEMEORY:{
            std::vector<uint8_t> buffer;
            int length = (int)this->bytesStream->dataLength;
            for (int i = 0; i < length; ++i)
            {
                uint8_t value = *(this->bytesStream->dataPtr + i);
                buffer.push_back(value);
            }    
            // std::cout << std::hex << "FINTO"  <<  std::endl;
            this->bytesStream->bytes = new std::istrstream(reinterpret_cast<const char*>(buffer.data()), buffer.size());
            this->Parse(this->bytesStream->bytes);
            break;
        }
    }
}

void Decoder::OnOK()
{
    // std::cout << "Decoder OnOK()" << std::endl;
    std::string jsonString = this->jsonFile.dump();
    Napi::String result =  String::New(Env(), jsonString);
    if(!this->sync) {
        Callback().Call({Env().Null(), result});
    }else{
        this->deferred.Resolve(result);
    }
}

void Decoder::OnError(const Error& e)
{
    // std::cout << "Decoder OnError()" << std::endl;
    MyError error = Worker::GetError();
    Object jsError = Object::New(Env());
    jsError.Set("code", (int)error.code);
    jsError.Set("message", error.message);
    if(!this->sync) {
        Callback().Call({ jsError, Env().Null()});
    }else{
        this->deferred.Reject(jsError);
    }

}

void Decoder::Destroy()
{
    // std::cout << "Decoder Destroy()" << std::endl;
    switch(this->source)
    {
        case Source::FILE: 
            this->fileStream->file->close();
            delete this->fileStream->file;
            delete this->fileStream;
            break;
        case Source::MEMEORY: 
            // this->bytesStream->dataPtr non serve grazie al UNref viene deallocata da GC di Javascropt
            this->bytesStream->dataRef.Unref();
            delete this->bytesStream->bytes;
            delete this->bytesStream;
            break;
    }
    Worker::Destroy();
}