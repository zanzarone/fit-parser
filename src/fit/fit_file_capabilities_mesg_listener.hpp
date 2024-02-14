/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2024 Garmin International, Inc.
// Licensed under the Flexible and Interoperable Data Transfer (FIT) Protocol License; you
// may not use this file except in compliance with the Flexible and Interoperable Data
// Transfer (FIT) Protocol License.
/////////////////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 21.133.0Release
// Tag = production/release/21.133.0-0-g6002091
/////////////////////////////////////////////////////////////////////////////////////////////


#if !defined(FIT_FILE_CAPABILITIES_MESG_LISTENER_HPP)
#define FIT_FILE_CAPABILITIES_MESG_LISTENER_HPP

#include "fit_file_capabilities_mesg.hpp"

namespace fit
{

class FileCapabilitiesMesgListener
{
public:
    virtual ~FileCapabilitiesMesgListener() {}
    virtual void OnMesg(FileCapabilitiesMesg& mesg) = 0;
};

} // namespace fit

#endif // !defined(FIT_FILE_CAPABILITIES_MESG_LISTENER_HPP)
