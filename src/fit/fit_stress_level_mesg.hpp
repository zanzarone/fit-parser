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


#if !defined(FIT_STRESS_LEVEL_MESG_HPP)
#define FIT_STRESS_LEVEL_MESG_HPP

#include "fit_mesg.hpp"

namespace fit
{

class StressLevelMesg : public Mesg
{
public:
    class FieldDefNum final
    {
    public:
       static const FIT_UINT8 StressLevelValue = 0;
       static const FIT_UINT8 StressLevelTime = 1;
       static const FIT_UINT8 Invalid = FIT_FIELD_NUM_INVALID;
    };

    StressLevelMesg(void) : Mesg(Profile::MESG_STRESS_LEVEL)
    {
    }

    StressLevelMesg(const Mesg &mesg) : Mesg(mesg)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of stress_level_value field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsStressLevelValueValid() const
    {
        const Field* field = GetField(0);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns stress_level_value field
    ///////////////////////////////////////////////////////////////////////
    FIT_SINT16 GetStressLevelValue(void) const
    {
        return GetFieldSINT16Value(0, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set stress_level_value field
    ///////////////////////////////////////////////////////////////////////
    void SetStressLevelValue(FIT_SINT16 stressLevelValue)
    {
        SetFieldSINT16Value(0, stressLevelValue, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of stress_level_time field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsStressLevelTimeValid() const
    {
        const Field* field = GetField(1);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns stress_level_time field
    // Units: s
    // Comment: Time stress score was calculated
    ///////////////////////////////////////////////////////////////////////
    FIT_DATE_TIME GetStressLevelTime(void) const
    {
        return GetFieldUINT32Value(1, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set stress_level_time field
    // Units: s
    // Comment: Time stress score was calculated
    ///////////////////////////////////////////////////////////////////////
    void SetStressLevelTime(FIT_DATE_TIME stressLevelTime)
    {
        SetFieldUINT32Value(1, stressLevelTime, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

};

} // namespace fit

#endif // !defined(FIT_STRESS_LEVEL_MESG_HPP)
