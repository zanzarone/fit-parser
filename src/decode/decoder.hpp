
#pragma once
#ifndef DECODER_H
#define DECODER_H

#include <napi.h>
#include "../configuration/defines.hpp"
#include "../worker/worker.hpp"
#include "../fit/fit_decode.hpp"
#include "../fit/fit_mesg_broadcaster.hpp"
#include "../fit/fit_developer_field_description.hpp"
#include "../fit/fit_session_mesg.hpp"
#include "../fit/fit_session_mesg_listener.hpp"

using namespace Napi;

class Decoder : public Worker, public fit::MesgListener, public fit::DeveloperFieldDescriptionListener
{
public:
    Decoder(Napi::Env &env, Buffer<uint8_t> &data, Object&options);
    Decoder(Napi::Env &env, Buffer<uint8_t> &data, Object&options,  Function &callback);
    Decoder(Napi::Env &env, std::string filepath, Object&options, Function &callback);
    Decoder(Napi::Env &env, std::string filepath, Object&options);
    ~Decoder() override;
    
public:
    void Execute() override;

protected:
    void OnOK() override;
    void OnError(const Error& e) override;
    void Destroy() override;
private:
    void AddValueToJSONField(const fit::FieldBase &field, const fit::Profile::MESG_INDEX index, JSON *jsonMesg);
    void OnMesg(fit::Mesg &mesg) override;
    void OnDeveloperFieldDescription(const fit::DeveloperFieldDescription &desc) override { }
    void Parse(std::istream *stream);

private:
    void Compose(JSON *jsonMesg,std::string msgName,int msgNum );

private:
    JSON jsonFile;
};


#endif // DECODER_H
