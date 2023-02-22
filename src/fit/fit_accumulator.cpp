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


#include "fit_accumulator.hpp"

namespace fit
{

FIT_UINT32 Accumulator::Accumulate(const FIT_UINT16 mesgNum, const FIT_UINT8 destFieldNum, const FIT_UINT32 value, const FIT_UINT8 bits)
{
   int i;
   AccumulatedField accumField;

   for (i = 0; i < (int)fields.size(); i++)
   {
       accumField = fields.at(i);
       if ( ( accumField.mesgNum == mesgNum ) && ( accumField.destFieldNum == destFieldNum ) )
         break;
   }

   if (i == (int)fields.size()) {
      fields.push_back(AccumulatedField(mesgNum, destFieldNum));
   }

   return fields[i].Accumulate(value, bits);
}

void Accumulator::Set(const FIT_UINT16 mesgNum, const FIT_UINT8 destFieldNum, const FIT_UINT32 value)
{
    int i;
    AccumulatedField accumField;

    for (i = 0; i < (int)fields.size(); i++)
    {
        accumField = fields.at(i);
        if ( ( accumField.mesgNum == mesgNum ) && ( accumField.destFieldNum == destFieldNum ) )
            break;
    }

    if (i == (int)fields.size()) {
        accumField = AccumulatedField(mesgNum, destFieldNum);
        fields.push_back(accumField);
    }
    fields[i].Set(value);
}

} // namespace fit
