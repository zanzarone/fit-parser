/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2023 Garmin International, Inc.
// Licensed under the Flexible and Interoperable Data Transfer (FIT) Protocol License; you
// may not use this file except in compliance with the Flexible and Interoperable Data
// Transfer (FIT) Protocol License.
/////////////////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 21.101Release
// Tag = production/release/21.101.00-0-gceb92d5
/////////////////////////////////////////////////////////////////////////////////////////////


#if !defined(FIT_TIME_IN_ZONE_MESG_LISTENER_HPP)
#define FIT_TIME_IN_ZONE_MESG_LISTENER_HPP

#include "fit_time_in_zone_mesg.hpp"

namespace fit
{

class TimeInZoneMesgListener
{
public:
    virtual ~TimeInZoneMesgListener() {}
    virtual void OnMesg(TimeInZoneMesg& mesg) = 0;
};

} // namespace fit

#endif // !defined(FIT_TIME_IN_ZONE_MESG_LISTENER_HPP)
