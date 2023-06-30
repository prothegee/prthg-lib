#include "prthgcpp/inc/Cryptography.h"

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


prthgcpp::CCryptography::CCryptography()
{
}

prthgcpp::CCryptography::~CCryptography()
{
}








std::string prthgcpp::CCryptography::GenerateSHA(std::string input, const prthgcpp::ECCryptShaLength shaLength) const
{
    std::string result;


    switch (shaLength)
    {
        case ECCryptShaLength::L40:
        {
            CryptoPP::SHA1 hash;
            CryptoPP::byte digest[CryptoPP::SHA1::DIGESTSIZE];
            CryptoPP::HexEncoder encoder;

            hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

            encoder.Attach(new CryptoPP::StringSink(result));
            encoder.Put(digest, sizeof(digest));
            encoder.MessageEnd();
        }
        break;


        case ECCryptShaLength::L56:
        {
            CryptoPP::SHA224 hash;
            CryptoPP::byte digest[CryptoPP::SHA224::DIGESTSIZE];
            CryptoPP::HexEncoder encoder;

            hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

            encoder.Attach(new CryptoPP::StringSink(result));
            encoder.Put(digest, sizeof(digest));
            encoder.MessageEnd();
        }
        break;


        case ECCryptShaLength::L64:
        {
            CryptoPP::SHA256 hash;
            CryptoPP::byte digest[CryptoPP::SHA256::DIGESTSIZE];
            CryptoPP::HexEncoder encoder;

            hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

            encoder.Attach(new CryptoPP::StringSink(result));
            encoder.Put(digest, sizeof(digest));
            encoder.MessageEnd();
        }
        break;


        case ECCryptShaLength::L96:
        {
            CryptoPP::SHA384 hash;
            CryptoPP::byte digest[CryptoPP::SHA384::DIGESTSIZE];
            CryptoPP::HexEncoder encoder;

            hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

            encoder.Attach(new CryptoPP::StringSink(result));
            encoder.Put(digest, sizeof(digest));
            encoder.MessageEnd();
        }
        break;


        case ECCryptShaLength::L128:
        {
            CryptoPP::SHA512 hash;
            CryptoPP::byte digest[CryptoPP::SHA512::DIGESTSIZE];
            CryptoPP::HexEncoder encoder;

            hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

            encoder.Attach(new CryptoPP::StringSink(result));
            encoder.Put(digest, sizeof(digest));
            encoder.MessageEnd();
        }
        break;
    }


    return result;
}




std::string prthgcpp::CCryptography::GeneratePasswordHasher(std::string input, const prthgcpp::ECCryptPasswordHasher passwordHasher, std::string salt) const
{
    std::string result;


    switch (passwordHasher)
    {
        case ECCryptPasswordHasher::SCRYPT:
        {
            std::string passwd_input(input), salt_input(salt);

            CryptoPP::word64 cost=1024, block=8, parallelization=16;

            CryptoPP::SecByteBlock derived(256);
            CryptoPP::Scrypt scrypt;

            CryptoPP::AlgorithmParameters params = 
                CryptoPP::MakeParameters("Cost", cost)
                ("BlockSize", block)("Parallelization", parallelization)
                ("Salt", CryptoPP::ConstByteArrayParameter(
                    (const CryptoPP::byte*)&salt_input[0], salt_input.size()));

            scrypt.DeriveKey(derived, derived.size(),
                (const CryptoPP::byte*)&passwd_input[0], passwd_input.size(), params);

            CryptoPP::StringSource(derived, derived.size(), true,
                new CryptoPP::HexEncoder(new CryptoPP::StringSink(result)));
        }
        break;
    }


    return result;
}




std::string prthgcpp::CCryptography::StreamCipher(const prthgcpp::ECCryptCipherMode cipherMode, const prthgcpp::ECCryptStreamCipherMode streamCipherMode, std::string input, int initializeKey, int initializeVector) const
{
    std::string result;


    switch (cipherMode)
    {
        case ECCryptCipherMode::encrypt:
        {
            if (streamCipherMode == ECCryptStreamCipherMode::CBC_AES)
            {
                CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];
                memset(key, initializeKey, CryptoPP::AES::DEFAULT_KEYLENGTH);
                memset(iv, initializeVector, CryptoPP::AES::BLOCKSIZE);

                CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
                CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);

                CryptoPP::StreamTransformationFilter encrypt(cbcEncryption, new CryptoPP::StringSink(result));
                encrypt.Put(reinterpret_cast<const unsigned char*>(input.c_str()), input.length());
                encrypt.MessageEnd();
            }
        }
        break;




        case ECCryptCipherMode::decrypt:
        {
            if (streamCipherMode == ECCryptStreamCipherMode::CBC_AES)
            {
                CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];
                memset(key, initializeKey, CryptoPP::AES::DEFAULT_KEYLENGTH);
                memset(iv, initializeVector, CryptoPP::AES::BLOCKSIZE);

                CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
                CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);

                CryptoPP::StreamTransformationFilter decrypt(cbcDecryption, new CryptoPP::StringSink(result));
                decrypt.Put(reinterpret_cast<const unsigned char*>( input.c_str() ), input.size());
                decrypt.MessageEnd();
            }
        }
        break;
    }


    return result;
}
