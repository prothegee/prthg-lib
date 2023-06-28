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




bool prthgcpp::CCryptography::InputIsAlphanumeric(const std::string input) const
{
    auto itter = std::find_if(input.begin(), input.end(), [](char const& c)
    {
        return !isalnum(c);
    });

    return itter == input.end();
}




std::string prthgcpp::CCryptography::GenerateAlphanumeric(int length) const
{
    std::string result;


    if (length <= 4) { length = 4; }

    char alphanum[] =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";

    result.reserve(length);

    // srand(time(0));

    for (int i = 0; i < length; i++)
    {
        result += alphanum[rand() % (sizeof(alphanum) - 1)];
    }


    return result;
}




std::string prthgcpp::CCryptography::ForceInputToCaseOf(std::string input, const prthgcpp::ECLetterCase letterCase) const
{
    std::string result;


    result.reserve(input.length());

    switch (letterCase)
    {
        case ECLetterCase::lowercase:
        {
            for (int i = 0; i < input.length(); i++)
            {
                result += tolower(input[i]);
            }
        }
        break;


        case ECLetterCase::uppercase:
        {
            for (int i = 0; i < input.length(); i++)
            {
                result += toupper(input[i]);
            }
        }
        break;
    }


    return result;
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
