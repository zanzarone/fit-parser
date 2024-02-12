/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2023 Garmin International, Inc.
// Licensed under the Flexible and Interoperable Data Transfer (FIT) Protocol License; you
// may not use this file except in compliance with the Flexible and Interoperable Data
// Transfer (FIT) Protocol License.
/////////////////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 21.126.0Release
// Tag = production/release/21.126.0-0-g0576dfe
/////////////////////////////////////////////////////////////////////////////////////////////


#if !defined(FIT_DEVELOPER_FIELD_DEFINITION_HPP)
#define FIT_DEVELOPER_FIELD_DEFINITION_HPP

#include <iosfwd>
#include "fit.hpp"
#include "fit_field_description_mesg.hpp"
#include "fit_developer_data_id_mesg.hpp"

namespace fit
{
class DeveloperField;

class DeveloperFieldDefinition
{
public:
    DeveloperFieldDefinition();
    DeveloperFieldDefinition(const DeveloperFieldDefinition& other);
    DeveloperFieldDefinition(FIT_UINT8 fieldNum, FIT_UINT8 size, FIT_UINT8 developerDataIndex);
    DeveloperFieldDefinition(const FieldDescriptionMesg& desc, const DeveloperDataIdMesg& developer, FIT_UINT8 size);
    explicit DeveloperFieldDefinition(const DeveloperField& field);
    virtual ~DeveloperFieldDefinition();

    FIT_BOOL IsDefined() const;
    FIT_UINT8 GetNum() const;
    FIT_UINT8 GetSize() const;
    FIT_UINT8 GetType() const;
    FIT_UINT8 GetDeveloperDataIndex() const;
    const FieldDescriptionMesg& GetDescription() const;
    const DeveloperDataIdMesg& GetDeveloper() const;

    FIT_BOOL operator==(const DeveloperFieldDefinition& field) const;
    FIT_BOOL operator!=(const DeveloperFieldDefinition& field) const;
    DeveloperFieldDefinition& operator=(const DeveloperFieldDefinition& other);
    FIT_UINT8 Write(std::ostream &file) const;

private:
    FIT_UINT8 num;
    FIT_UINT8 size;
    FIT_UINT8 developerDataIndex;

    FieldDescriptionMesg* mesg;
    DeveloperDataIdMesg* developer;
};

} // namespace fit

#endif // defined(FIT_FIELD_DEFINITION_HPP)
