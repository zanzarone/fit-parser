////////////////////////////////////////////////////////////////////////////////
// The following FIT Protocol software provided may be used with FIT protocol
// devices only and remains the copyrighted property of Garmin Canada Inc.
// The software is being provided on an "as-is" basis and as an accommodation,
// and therefore all warranties, representations, or guarantees of any kind
// (whether express, implied or statutory) including, without limitation,
// warranties of merchantability, non-infringement, or fitness for a particular
// purpose, are specifically disclaimed.
//
// Copyright 2021 Garmin International, Inc.
////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 21.67Release+Custom
// Tag = production/akw/21.67.00-0-gd790f76b
////////////////////////////////////////////////////////////////////////////////


#if !defined(FIT_BUFFER_ENCODE_HPP)
#define FIT_BUFFER_ENCODE_HPP

#include <iosfwd>
#include <sstream>
#include <string>
#include "fit.hpp"
#include "fit_mesg.hpp"
#include "fit_mesg_definition.hpp"
#include "fit_mesg_definition_listener.hpp"
#include "fit_mesg_listener.hpp"

namespace fit
{

class BufferEncode : public MesgListener, public MesgDefinitionListener
{
   public:
      BufferEncode(void);
      void Open();
      void Write(const MesgDefinition& mesgDef);
      void Write(const Mesg& mesg);
      void Write(const std::vector<Mesg>& mesgs);
      std::string Close(void);
      void OnMesg(Mesg& mesg);
      void OnMesgDefinition(MesgDefinition& mesgDef);

   private:
      std::stringstream stringWriter;
      FIT_UINT32 dataSize;
      MesgDefinition lastMesgDefinition[FIT_MAX_LOCAL_MESGS];
};

} // namespace fit

#endif // defined(FIT_BUFFER_ENCODE_HPP)
