#include <fstream>
#include <iostream>
#include <cstdlib>
#include "encoder.hpp"
#include "../fit/fit_encode.hpp"
#include "../fit/fit_mesg_broadcaster.hpp"
#include "../fit/fit_file_id_mesg.hpp"
#include "../fit/fit_date_time.hpp"
#include "../configuration/utility.hpp"

Encoder::Encoder(Napi::Env &env,std::string filePath, std::string jsonFileString, Object&options, Function& callback) : Worker(env, callback, &options) {
   this->source = Source::STRING;
   this->fileStream = new FileStream();
   this->filePath = filePath;
   this->jsonFileString = jsonFileString;
}

Encoder::Encoder(Napi::Env &env,std::string filePath, Buffer<uint8_t> &data, Object&options, Function& callback) : Worker(env, callback, &options) {
   this->source = Source::BUFFER;
   this->bytesStream = new BytesStream();
   this->filePath = filePath;
   this->bytesStream->dataLength = data.Length();
   this->bytesStream->dataPtr = data.Data();
   this->bytesStream->dataRef = ObjectReference::New(data, 1);
}

Encoder::Encoder(Napi::Env &env,std::string filePath, std::string jsonFileString, Object&options): Worker(env, &options)
{
   this->source = Source::STRING;
   this->fileStream = new FileStream();
   this->filePath = filePath;
   this->jsonFileString = jsonFileString;
}

Encoder::Encoder(Napi::Env &env,std::string filePath, Buffer<uint8_t> &data, Object&options) : Worker(env, &options)
{
   this->source = Source::BUFFER;
   this->bytesStream = new BytesStream();
   this->filePath = filePath;
   this->bytesStream->dataLength = data.Length();
   this->bytesStream->dataPtr = data.Data();
   this->bytesStream->dataRef = ObjectReference::New(data, 1);
}

Encoder::~Encoder(){ };

void Encoder::EnumerateFields(fit::Mesg * fitMesg, JSON fields)
{
   try
   {
      for (auto field = fields.begin(); field != fields.end(); ++field)
      {
         //?
         JSON jsonField = field.value();
         FIT_UINT16 msgNum = fitMesg->GetNum();
         if(  !jsonField.contains("num") ) 
         { 
            /// il json ha una chiave null non posso ricostruire il messaggio
            Worker::SetCustomWarnings(EncoderWarningCodes::JSON_FIELD_WITHOUT_LOCAL_NUM, "No local num specified for field " + field.key() );
            continue;
         }
         FIT_UINT8 fieldNum = jsonField["num"];
         fit::Field fitField(msgNum, fieldNum);
         if( fitField.GetNumValues() > 1 && fitField.GetType() != FIT_BASE_TYPE_STRING)
         {
            //? se il field non contiene value imposto il default(INVALIDO).
            std::string rawValues = jsonField["value"];
            std::vector<unsigned char> bytes = Utility::toBinary(rawValues);
            int length = (int)bytes.size();
            for(int i = 0; i<length; i++)
            {
               fitField.SetUINT8Value(bytes.at(i),i);
            }
         }
         else {
            switch (fitField.GetType())
            {
               case FIT_BASE_TYPE_ENUM:{
                  FIT_ENUM calculatedValue = jsonField["value"];
                  fitField.SetENUMValue(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_SINT8:{
                  FIT_SINT8 calculatedValue = jsonField["value"];
                  fitField.SetSINT8Value(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_UINT8:{
                  FIT_UINT8 calculatedValue = jsonField["value"];
                  fitField.SetUINT8Value(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_SINT16:{
                  FIT_SINT16 calculatedValue = jsonField["value"];
                  fitField.SetSINT16Value(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_UINT16:{
                  FIT_UINT16 calculatedValue = jsonField["value"];
                  fitField.SetUINT16Value(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_SINT32:{
                  FIT_SINT32 calculatedValue = jsonField["value"];
                  fitField.SetSINT32Value(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_UINT32:{
                  FIT_UINT32 calculatedValue = jsonField["value"];
                  fitField.SetUINT32Value(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_STRING:{
                  std::string calculatedValue = jsonField["value"];
                  std::wstring wsTmp(calculatedValue.begin(), calculatedValue.end());
                  fitField.SetSTRINGValue(wsTmp);
               }
               break;
               case FIT_BASE_TYPE_FLOAT32:{
                  FIT_FLOAT32 calculatedValue = jsonField["value"];
                  fitField.SetFLOAT32Value(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_FLOAT64:{
                  FIT_FLOAT64 calculatedValue = jsonField["value"];
                  fitField.SetFLOAT64Value(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_UINT8Z:{
                  FIT_UINT8Z calculatedValue = jsonField["value"];
                  fitField.SetUINT8ZValue(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_UINT16Z:{
                  FIT_UINT16Z calculatedValue = jsonField["value"];
                  fitField.SetUINT16ZValue(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_UINT32Z:{
                  FIT_UINT32Z calculatedValue = jsonField["value"];
                  fitField.SetUINT32ZValue(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_BYTE:{
                  FIT_BYTE calculatedValue = jsonField["value"];
                  fitField.SetBYTEValue(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_SINT64:{
                  FIT_SINT64 calculatedValue = jsonField["value"];
                  fitField.SetSINT64Value(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_UINT64:{
                  FIT_UINT64 calculatedValue = jsonField["value"];
                  fitField.SetUINT64Value(calculatedValue);
               }
               break;
               case FIT_BASE_TYPE_UINT64Z:{
                  FIT_UINT64Z calculatedValue = jsonField["value"];
                  fitField.SetUINT64ZValue(calculatedValue);
               }
               break;
            
               default:
                  break;
            }
         }
         fitMesg->AddField(fitField);
      }
   } catch(const std::exception& e)
   {
      if(this->options.force){
         Worker::SetCustomWarnings(EncoderWarningCodes::JSON_FIELD_PARSE_EXCEPTION, e.what() );
      }else{
         throw e;
      }
   }
}

void Encoder::Execute() 
{
            std::cout << "Encoder 0" << std::endl;
   std::fstream file;
   try
   {
      std::cout << "Encoder a" << std::endl;
      file.open(this->filePath, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
      if (!file.is_open())
      {
         const std::string error ="Cannot open file at path:" + this->filePath ;//+ e.what();
         Worker::SetCustomError(StatusCode::COULD_NOT_OPEN,error);
         this->SetError(error);
         return;
      }
   }
   catch(const std::exception& e)
   {
      std::cout << "Encoder c" << std::endl;
      const std::string error ="Error opening file:" + std::string(e.what());
      Worker::SetCustomError(StatusCode::COULD_NOT_OPEN, error);
      this->SetError(error);   
      return;   
   }

   std::cout << "Encoder 00" << std::endl;
   
   JSON fileObject;
   try
   {
      switch(this->source)
      {
         case Source::STRING: {
            // parsing input with a syntax error
            fileObject = JSON::parse(this->jsonFileString);
            break;
         }
         case Source::BUFFER: {
            std::cout << "Encoder 1" << std::endl;
            std::vector<uint8_t> buffer;
            int length = (int)this->bytesStream->dataLength;
            std::cout << "Encoder 2" << std::endl;
            for (int i = 0; i < length; ++i)
            {
               uint8_t value = *(this->bytesStream->dataPtr + i);
               buffer.push_back(value);
            }
            this->bytesStream->bytes = new std::istrstream(reinterpret_cast<const char*>(buffer.data()), buffer.size()); 
            fileObject = JSON::parse(*this->bytesStream->bytes);
            break;
         }
      }
   }
   catch (JSON::parse_error& e)
   {
      const std::string error = "Malformed string. " + std::string(e.what()) ;//+ e.what();
      Worker::SetCustomError(StatusCode::JSON_PARSE_EXCEPTION,error);
      this->SetError(error);
      file.close();
      return;
   }

   fit::Encode encode( fit::ProtocolVersion::V20 );
   encode.Open(file);

   try
   {
      for (auto message = fileObject.begin(); message != fileObject.end(); ++message)
      {
         JSON value = message.value();
         std::string msgName = message.key();
         if( msgName.empty() ) 
         { 
            //? il json ha una chiave null non posso ricostruire il messaggio
            Worker::SetCustomWarnings(EncoderWarningCodes::JSON_MESG_WITHOUT_LOCAL_NUM, "No local num specified for message " + message.key() );
            continue;
         }
         fit::Mesg fitMesg(msgName);
         if(this->SkipMessage(fitMesg.GetNum()))
            continue;      
         //? se la chiave e' di tipo <mesg> allora il campo contiene
         //? una collezione di messaggi
         if( value.contains("msgs") ) 
         {
            //? il messaggio e' multiplo, prendo array dei messaggi
            JSON mesgs  = value["msgs"];
            for (auto message = mesgs.begin(); message != mesgs.end(); ++message)
            {
               fit::Mesg fitMesg(msgName);
               JSON fields = message.value();
               //? 'num' field of fit mesg is useless during the enumeration of fields
               fields.erase("num");
               this->EnumerateFields(&fitMesg, fields);
               encode.Write(fitMesg);
            }
         }
         else {
            //? 'num' field of fit mesg is useless during the enumeration of fields
            value.erase("num");
            this->EnumerateFields(&fitMesg, value);
            encode.Write(fitMesg);
         }
      }
   }
   catch(const std::exception& e)
   {      
      const std::string error = std::string(e.what()) ;//+ e.what();
      Worker::SetCustomError(StatusCode::ENCODE_EXCEPTION,error);
      this->SetError(error);
      file.close();
      return;
   }

   if (!encode.Close())
   {
      const std::string error ="Error closing encode"  ;//+ e.what();
      Worker::SetCustomError(StatusCode::ENCODE_CLOSE_EXCEPTION,error);
      this->SetError(error);
   }
   file.close();
}

void Encoder::OnOK() 
{
   JSON warnings = Worker::GetWarnings();
   if(!this->sync) {
      if(warnings.empty()){
         Callback().Call({Env().Null(), Env().Null()});
      }else{
         Object jsWarn = Object::New(Env());
         jsWarn.Set("warnings", warnings.dump());
         Callback().Call({Env().Null(), jsWarn});
      }
   }else{
      if(warnings.empty()){
         this->deferred.Resolve(Env().Null());
      }else{
         Object jsWarn = Object::New(Env());
         jsWarn.Set("warnings", warnings.dump());
         this->deferred.Resolve(jsWarn);
      }
   }
}

void Encoder::OnError(const Error& e)
{
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

void Encoder::Destroy()
{
   //  std::cout << "Encoder Destroy()" << std::endl;
    switch(this->source)
    {
        case Source::STRING: 
            delete this->fileStream;
            /// non devo fare niente
            break;
        case Source::BUFFER: 
            // this->bytesStream->dataPtr non serve grazie al UNref viene deallocata da GC di Javascropt
            this->bytesStream->dataRef.Unref();
            delete this->bytesStream->bytes;
            delete this->bytesStream;
            break;
    }
    Worker::Destroy();
}
