/**
 * @file Cryptography.h
 * @author Prana Ron (prothegee@protonmail.com)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prothegee@protonmail.com)
 * 
 */
#ifndef PRTHGCPP_CRYPTOHRAPHY_H
#define PRTHGCPP_CRYPTOHRAPHY_H
#include "prthgcpp/config.gen.h"


#ifdef __INC_PRTHGCPP_CRYPTOPP__
#include <iostream>
#include <string>

#include "prthgcpp/enums/CryptEnums.h"
#include "prthgcpp/enums/LetterEnums.h"
#include "prthgcpp/classes/Utility.h"


#include <cryptopp/ec2n.h>
#include <cryptopp/hex.h>
#include <cryptopp/modes.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/secblock.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/words.h>

#include <cryptopp/blake2.h>
#include <cryptopp/scrypt.h>
#include <cryptopp/sha.h>
#include <cryptopp/gcm.h>
#include <cryptopp/aes.h>
#include <cryptopp/chacha.h>


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
         * @brief generate sha1 from input
         * 
         * @note return length will be 40
         * 
         * @param input 
         * @return std::string 
         */
        std::string GenerateSHA1(const std::string &input) const;

        /**
         * @brief generate sha224 from input
         * 
         * @note return length will be 56
         * 
         * @param input 
         * @return std::string 
         */
        std::string GenerateSHA224(const std::string &input) const;

        /**
         * @brief generate sha256 from input
         * 
         * @note return length will be 64
         * 
         * @param input 
         * @return std::string 
         */
        std::string GenerateSHA256(const std::string &input) const;

        /**
         * @brief generate sha384 from input
         * 
         * @note return length will be 96
         * 
         * @param input 
         * @return std::string 
         */
        std::string GenerateSHA384(const std::string &input) const;

        /**
         * @brief generate sha512 from input
         * 
         * @note return length will be 128
         * 
         * @param input 
         * @return std::string 
         */
        std::string GenerateSHA512(const std::string &input) const;


        /**
         * @brief generate blake2b from input
         * 
         * @note return length will be 128
         * 
         * @param input 
         * @return std::string 
         */
        std::string GenerateBLAKE2b(const std::string &input) const;


        /**
         * @brief generate password hasher using scrypt
         * 
         * @param input 
         * @param salt 
         * @return std::string 
         */
        std::string GenerateHasherSCRYPT(std::string input, std::string salt) const;


        /**
         * @brief encrypt input using XChaCha20 stream cipher
         * 
         * @note initializeKey length must 32 byte e.g. abcdefghijklmnopqrstuvwxyz123456
         * @note initializeVector length must 24 byte e.g. abcdefghijklmnopqrstuvwx
         * 
         * @param input 
         * @param initializeVector 
         * @param initializeKey 
         * @return std::string 
         */
        std::string EncryptXChaCha20(std::string input, std::string initializeKey, std::string initializeVector) const;

        /**
         * @brief decrypt input using XChaCha20 stream cipher
         * 
         * @note initializeKey length must 32 byte e.g. abcdefghijklmnopqrstuvwxyz123456
         * @note initializeVector length must 24 byte e.g. abcdefghijklmnopqrstuvwx
         * 
         * @param input 
         * @param initializeVector 
         * @param initializeKey 
         * @return std::string 
         */
        std::string DecryptXChaCha20(std::string input, std::string initializeKey, std::string initializeVector) const;


        /**
         * @brief encrypt input using CBC AES stream cipher
         * 
         * @note initializeKey length must 9 byte and can't start from 0 e.g. 123456789
         * @note initializeVector length must 9 byte and can't start from 0 e.g. 987654321
         * 
         * @param input 
         * @param initializeKey 
         * @param initializeVector 
         * @return std::string 
         */
        std::string EncryptCBCAES(std::string input, int initializeKey, int initializeVector) const;

        /**
         * @brief decrypt input using CBC AES stream cipher
         * 
         * @note initializeKey length must 9 byte and can't start from 0 e.g. 123456789
         * @note initializeVector length must 9 byte and can't start from 0 e.g. 987654321
         * 
         * @param input 
         * @param initializeKey 
         * @param initializeVector 
         * @return std::string 
         */
        std::string DecryptCBCAES(std::string input, int initializeKey, int initializeVector) const;
    };


} // namespace prthgcpp


#endif // __INC_PRTHGCPP_CRYPTOPP__


#endif // PRTHGCPP_CRYPTOHRAPHY_H