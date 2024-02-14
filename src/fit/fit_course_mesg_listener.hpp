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


#if !defined(FIT_COURSE_MESG_LISTENER_HPP)
#define FIT_COURSE_MESG_LISTENER_HPP

#include "fit_course_mesg.hpp"

namespace fit
{

class CourseMesgListener
{
public:
    virtual ~CourseMesgListener() {}
    virtual void OnMesg(CourseMesg& mesg) = 0;
};

} // namespace fit

#endif // !defined(FIT_COURSE_MESG_LISTENER_HPP)
