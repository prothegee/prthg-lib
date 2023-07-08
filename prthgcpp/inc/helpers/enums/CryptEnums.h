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
    // enum of crypt SHA length
    enum ECryptShaLength : int
    {
        eCrypt_SHA_undefined = 0,
        eCrypt_SHA_L40,
        eCrypt_SHA_L56,
        eCrypt_SHA_L64,
        eCrypt_SHA_L96,
        eCrypt_SHA_L128,
    };


    // enum class of crypt password hasher
    enum class ECCryptHasherMode : int
    {
        undefined = 0,
        SCRYPT,
    };
    // enum of crypt password hasher
    enum ECryptHasherMode : int
    {
        eCrypt_HASHER_undefined = 0,
        eCrypt_HASHER_SCRYPT,
    };


    // enum class of crypt cipher mode
    enum class ECCryptCipherMode : int
    {
        undefined = 0,
        encrypt,
        decrypt,
    };
    // enum of crypt cipher mode
    enum ECryptCipherMode : int
    {
        eCrypt_cipher_undefined = 0,
        eCrypt_cipher_encrypt,
        eCrypt_cipher_decrypt,
    };


    // enum class of crypt stream cipher mode
    enum class ECCryptStreamCipherMode : int
    {
        undefined = 0,
        CBC_AES,
        XChaCha20,
    };
    enum ECryptStreamCipherMode : int
    {
        eCrypt_streamCipher_undefined = 0,
        eCrypt_streamCipher_CBC_AES,
        eCrypt_streamCipher_XChaCha20,
    };


} // namespace prthgcpp


#endif // PRTHGCPP_CRYPT_ENUMS_H