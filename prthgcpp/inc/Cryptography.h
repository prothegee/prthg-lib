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
         * @brief check if input is alphanumeric
         * 
         * @note this generator quality is average
         * @note you need add srand(time(0)) before call this function
         * 
         * @param input 
         * @return true 
         * @return false 
         */
        bool InputIsAlphanumeric(const std::string input) const;


        /**
         * @brief generate alphanumeric based on length param
         * 
         * @note length less than 4 will be set to 4
         * 
         * @param length 
         * @return std::string 
         */
        std::string GenerateAlphanumeric(int length) const;


        /**
         * @brief force input as letterCase param format
         * 
         * @param input 
         * @param letterCase 
         * @return std::string 
         */
        std::string ForceInputToCaseOf(std::string input, const prthgcpp::ECLetterCase letterCase) const;


        /**
         * @brief generate sha digest from input & based on length 2nd param input
         * 
         * @param input 
         * @param shaLength 
         * @return std::string 
         */
        std::string GenerateSHA(std::string input, const prthgcpp::ECCryptShaLength shaLength) const;


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
         * @note both initializeKey & initializeVector must 9 byte length and cannot start with 0
         * @note e.g. 123456789 or 987654321
         * 
         * @param cipherMode 
         * @param streamCipherMode 
         * @param input 
         * @param initializeKey 
         * @param initializeVector 
         * @return std::string 
         */
        std::string StreamCipher(const prthgcpp::ECCryptCipherMode cipherMode, const prthgcpp::ECCryptStreamCipherMode streamCipherMode, std::string input, int initializeKey, int initializeVector) const;
    };


} // namespace prthgcpp


#endif // PRTHGCPP_CRYPTOHRAPHY_H