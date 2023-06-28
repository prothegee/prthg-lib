/**
 * @file CryptEnums.h
 * @author Prana Ron (prthg@proton.me)
 * 
 * @brief enum (constant/class) for crypt keyword/prefix
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
 */
#ifndef PRTHGCPP_CRYPT_ENUMS_H
#define PRTHGCPP_CRYPT_ENUMS_H


namespace prthgcpp
{


    // enum class of crypt SHA length
    enum class ECCryptShaLength : int
    {
        undefined = 0,
        L40,
        L56,
        L64,
        L96,
        L128,
    };


} // namespace prthgcpp


#endif // PRTHGCPP_CRYPT_ENUMS_H