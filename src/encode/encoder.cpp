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
   this->source = Source::FILE;
   this->fileStream = new FileStream();
   this->fileStream->filePath = filePath;
   this->jsonFileString = jsonFileString;
}

Encoder::Encoder(Napi::Env &env,std::string filePath, Buffer<uint8_t> &data, Object&options, Function& callback) : Worker(env, callback, &options) {
   this->source = Source::MEMORY;
   this->bytesStream = new BytesStream();
   this->bytesStream->dataLength = data.Length();
   this->bytesStream->dataPtr = data.Data();
   this->bytesStream->dataRef = ObjectReference::New(data, 1);
}

Encoder::Encoder(Napi::Env &env,std::string filePath, std::string jsonFileString, Object&options): Worker(env, &options)
{
   this->source = Source::FILE;
   this->fileStream = new FileStream();
   this->fileStream->filePath = filePath;
   this->jsonFileString = jsonFileString;
}

Encoder::Encoder(Napi::Env &env,std::string filePath, Buffer<uint8_t> &data, Object&options) : Worker(env, &options)
{
   this->source = Source::MEMORY;
   this->bytesStream = new BytesStream();
   this->bytesStream->dataLength = data.Length();
   this->bytesStream->dataPtr = data.Data();
   this->bytesStream->dataRef = ObjectReference::New(data, 1);
}

Encoder::~Encoder(){ };

void Encoder::EnumerateFields(fit::Mesg * fitMesg, JSON fields)
{
   for (auto field = fields.begin(); field != fields.end(); ++field)
   {
      JSON jsonField = field.value();
      // std::cout << std::setw(2) << jsonField << '\n';
      std::string msgName = fitMesg->GetName();
      std::string fieldName = field.key();
      // std::cout << "CCCCC" << std::endl;
      if( fieldName.empty() ) 
      { 
         /// il json ha una chiave null non posso ricostruire il messaggio
         Worker::SetCustomWarnings(EncoderWarningCodes::JSON_FIELD_WITHOUT_LOCAL_NUM, "No local num specified for field " + field.key() );
         continue;
      }
      fit::Field fitField(fieldName, msgName);
      if( fitField.GetNumValues() > 1 && fitField.GetType() != FIT_BASE_TYPE_STRING)
      {
         /// se il field non contiene value imposto il default(INVALIDO).
         std::string rawValues = jsonField["value"];
         std::vector<unsigned char> bytes = Utility::toBinary(rawValues);
         int length = (int)bytes.size();
         for(int i = 0; i<length; i++)
         {
            fitField.SetUINT8Value(bytes.at(i),i);
         }
      }
      else {
         if( fitField.GetType() == FIT_BASE_TYPE_STRING ) {
            /// se il field non contiene value imposto il default(INVALIDO).
            std::string calculatedValue = jsonField["value"];
            std::wstring wsTmp(calculatedValue.begin(), calculatedValue.end());
            fitField.SetSTRINGValue(wsTmp);
         }
         else 
         {
            /// se il field non contiene value imposto il default(INVALIDO).
            FIT_FLOAT64 calculatedValue = jsonField["value"];
            fitField.AddValue(calculatedValue);
         }
      }
      fitMesg->AddField(fitField);
   }
}

void Encoder::Execute() 
{
   fit::Encode encode( fit::ProtocolVersion::V10 );
   std::fstream file;
   file.open(this->fileStream->filePath, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
   if (!file.is_open())
   {
      const std::string error ="Cannot open file at path:" + this->fileStream->filePath ;//+ e.what();
      Worker::SetCustomError(StatusCode::COULD_NOT_OPEN,error);
      this->SetError(error);
      return;
   }
   JSON fileObject;
   try
   {
      switch(this->source)
      {
         case Source::FILE: {
            // parsing input with a syntax error
            fileObject = JSON::parse(this->jsonFileString);
            break;
         }
         case Source::MEMORY: {
            std::vector<uint8_t> buffer;
            int length = (int)this->bytesStream->dataLength;
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
      return;
   }   
   encode.Open(file);

   for (auto message = fileObject.begin(); message != fileObject.end(); ++message)
   {
      // std::cout << "key: " << message.key() << "\n\n\n" << "value:" << message.value() << "\n\n\n";
      // std::cout << "key: " << message.key() << "\n\n\n";
      JSON value = message.value();
      std::string msgName = message.key();
      // std::cout << "CCCCC" << std::endl;
      if( msgName.empty() ) 
      { 
         /// il json ha una chiave null non posso ricostruire il messaggio
         Worker::SetCustomWarnings(EncoderWarningCodes::JSON_MESG_WITHOUT_LOCAL_NUM, "No local num specified for message " + message.key() );
         continue;
      }
      // std::cout << "1" << std::endl;
      fit::Mesg fitMesg(msgName);
         // std::cout << "4" << std::endl;
      if(this->SkipMessage(fitMesg.GetNum()))
         continue;
      /// se la chiave e' di tipo <mesg> allora il campo contiene
      /// una collezione di messaggi
      if( value.contains("msgs") ) 
      {
         /// il messaggio e' multiplo, prendo array dei messaggi
         JSON mesgs  = value["msgs"];
         for (auto message = mesgs.begin(); message != mesgs.end(); ++message)
         {
            JSON fields = message.value();
            this->EnumerateFields(&fitMesg, fields);
            encode.Write(fitMesg);
         }
      }
      else {
         /// altrimenti contiene un messaggio singolo.
         this->EnumerateFields(&fitMesg, value);
         encode.Write(fitMesg);
      }
   }
   if (!encode.Close())
   {
   // std::cout << "AD" << std::endl;
      const std::string error ="Error closing encode"  ;//+ e.what();
      Worker::SetCustomError(StatusCode::ENCODE_CLOSE_EXCEPTION,error);
      this->SetError(error);
      return;
   }
   // std::cout << "C" << std::endl;
   file.close();
}


void Encoder::OnOK() 
{
   // std::cout << "Encoder OnOK()" << std::endl;
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
   std::cout << "Encoder OnError()" << std::endl;
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
        case Source::FILE: 
            delete this->fileStream;
            /// non devo fare niente
            break;
        case Source::MEMORY: 
            // this->bytesStream->dataPtr non serve grazie al UNref viene deallocata da GC di Javascropt
            this->bytesStream->dataRef.Unref();
            delete this->bytesStream->bytes;
            delete this->bytesStream;
            break;
    }
    Worker::Destroy();
}
