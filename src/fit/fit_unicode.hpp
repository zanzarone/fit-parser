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


#if !defined(FIT_UNICODE_HPP)
#define FIT_UNICODE_HPP

#include <iosfwd>
#include <string>
#include "fit.hpp"

namespace fit
{

class Unicode
{
public:
    typedef std::string UTF8_STRING;    // UTF-8 encoded strings used for file/message input and output.
    typedef std::fstream UTF8_FSTREAM;
    typedef std::ofstream UTF8_OFSTREAM;
    typedef std::ifstream UTF8_IFSTREAM;
    typedef std::stringstream UTF8_SSTREAM;
    typedef std::ostringstream UTF8_OSSTREAM;
    typedef std::istringstream UTF8_ISSTREAM;

public:
    static Unicode::UTF8_STRING Encode_BaseToUTF8(const FIT_WSTRING& strSrc);
    static FIT_WSTRING Encode_UTF8ToBase(const Unicode::UTF8_STRING& strSrc);
    static Unicode::UTF8_STRING Copy_StdToUTF8(const std::string& strSrc);
    static std::string Copy_UTF8ToStd(const Unicode::UTF8_STRING& strSrc);
};

} // namespace fit

#endif // !defined(FIT_UNICODE_HPP)
