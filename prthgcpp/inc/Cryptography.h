/**
 * @file Cryptography.h
 * @author Prana Ron (prthg@proton.me)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
 */
#ifndef PRTHGCPP_CRYPTOHRAPHY_H
#define PRTHGCPP_CRYPTOHRAPHY_H
#include <iostream>
#include <string>

#include "prthgcpp/inc/helpers/enums/CryptEnums.h"
#include "prthgcpp/inc/helpers/enums/LetterEnums.h"


namespace prthgcpp
{


    /**
     * @brief prhtgcpp internal cryptography class
     * 
     */
    class CCryptography
    {
    private:
        /* data */


    protected:
        /* data */


    public:
        CCryptography(/* args */);
        ~CCryptography();


        /**
         * @brief generate sha digest from input & based on length 2nd param input
         * 
         * @param input 
         * @param shaLength 
         * @param lowerCase 
         * @return std::string 
         */
        std::string GenerateSHA(std::string input, const prthgcpp::ECCryptShaLength shaLength, const bool &lowerCase) const;


        std::string GenerateBLAKE2b(std::string input, const bool &lowerCase) const;


        /**
         * @brief generate password hasher
         * 
         * @note you may store your salt somewhere
         * 
         * @param input 
         * @param passwordHasher 
         * @param salt 
         * @return std::string 
         */
        std::string GeneratePasswordHasher(std::string input, const prthgcpp::ECCryptPasswordHasher passwordHasher, std::string salt) const;


        /**
         * @brief stream cipher mode to encrypt decrypt a message/input
         * 
         * @note for ECCryptStreamCipherMode::CBC_AES
         * @note both initializeKey & initializeVector must 9 byte length and cannot start with 0
         * @note e.g. 123456789 or 987654321
         * @note also both initializeKeyStr & initializeVectorStr will be ignore
         * @note --
         * @note for ECCryptStreamCipherMode::XChaCha20
         * @note both initializeKey & initializeVector will be ignore
         * @note also initializeKeyStr must 32 byte length
         * @note e.g. abcdefghijklmnopqrstuvwxyz123456
         * @note while initializeVectorStr must 24 byte length
         * @note e.g. abcdefghijklmnopqrstuvwx
         * 
         * @param cipherMode 
         * @param streamCipherMode 
         * @param input 
         * @param initializeKey 
         * @param initializeVector 
         * @param initializeKeyStr
         * @param initializeVectorStr 
         * @return std::string 
         */
        std::string StreamCipher(const prthgcpp::ECCryptCipherMode cipherMode, const prthgcpp::ECCryptStreamCipherMode streamCipherMode, std::string input, int initializeKey, int initializeVector, std::string initializeKeyStr, std::string initializeVectorStr) const;
    };


} // namespace prthgcpp


#endif // PRTHGCPP_CRYPTOHRAPHY_H