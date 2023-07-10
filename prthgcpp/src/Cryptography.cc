#include "prthgcpp/inc/Cryptography.h"


prthgcpp::CCryptography::CCryptography()
{
}

prthgcpp::CCryptography::~CCryptography()
{
}








std::string prthgcpp::CCryptography::GenerateSHA(std::string input, const prthgcpp::ECCryptShaLength shaLength, const int &letterCase) const
{
    std::string result, resultTmp;


    switch (shaLength)
    {
        case ECCryptShaLength::L40:
        {
            CryptoPP::SHA1 hash;
            CryptoPP::byte digest[CryptoPP::SHA1::DIGESTSIZE];
            CryptoPP::HexEncoder encoder;

            hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

            encoder.Attach(new CryptoPP::StringSink(resultTmp));
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

            encoder.Attach(new CryptoPP::StringSink(resultTmp));
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

            encoder.Attach(new CryptoPP::StringSink(resultTmp));
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

            encoder.Attach(new CryptoPP::StringSink(resultTmp));
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

            encoder.Attach(new CryptoPP::StringSink(resultTmp));
            encoder.Put(digest, sizeof(digest));
            encoder.MessageEnd();
        }
        break;
    }


    // if (lowerCase)
    // {
    //     prthgcpp::CUtility util;
    //     result = util.ForceInputToCaseOf(resultTmp, ECLetterCase::lowercase);
    // }
    // else
    // {
    //     result = resultTmp;
    // }
    prthgcpp::CUtility util;

    switch (letterCase)
    {
        case 0:
        {
            result = util.ForceInputToCaseOf(resultTmp, ECLetterCase::uppercase);
        }
        break;

        case 1:
        {
            result = util.ForceInputToCaseOf(resultTmp, ECLetterCase::lowercase);
        }
        break;

        case 2:
        {
            result.reserve(resultTmp.size());

            for (size_t i = 0; i < resultTmp.size(); i++)
            {
                // 0 is upper, 1 is lower
                int mixedCase = util.GetRandom(0, 1);

                if (mixedCase == 0 && isalpha(resultTmp[i]))
                {
                    std::string push{resultTmp[i]};
                    result += util.ForceInputToCaseOf(push, ECLetterCase::uppercase);
                }
                else if (mixedCase == 1 && isalpha(resultTmp[i]))
                {
                    std::string push{resultTmp[i]};
                    result += util.ForceInputToCaseOf(push, ECLetterCase::lowercase);
                }
                else
                {
                    std::string push{resultTmp[i]};
                    result += push;
                }
            }
        }
        break;

        default:
        {
            result = util.ForceInputToCaseOf(resultTmp, ECLetterCase::uppercase);
        }
        break;
    }


    return result;
}








std::string prthgcpp::CCryptography::GenerateBLAKE2b(std::string input, const int &letterCase) const
{
    std::string result, resultTmp;


    CryptoPP::BLAKE2b hash;
    CryptoPP::byte digest[CryptoPP::BLAKE2b::DIGESTSIZE];
    CryptoPP::HexEncoder encoder;

    hash.CalculateDigest(digest, (CryptoPP::byte*)input.c_str(), input.length());

    encoder.Attach(new CryptoPP::StringSink(resultTmp));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    // if (lowerCase)
    // {
    //     prthgcpp::CUtility util;
    //     result = util.ForceInputToCaseOf(resultTmp, ECLetterCase::lowercase);
    // }
    // else
    // {
    //     result = resultTmp;
    // }
    prthgcpp::CUtility util;

    switch (letterCase)
    {
        case 0:
        {
            result = util.ForceInputToCaseOf(resultTmp, ECLetterCase::uppercase);
        }
        break;

        case 1:
        {
            result = util.ForceInputToCaseOf(resultTmp, ECLetterCase::lowercase);
        }
        break;

        case 2:
        {
            result.reserve(resultTmp.size());

            for (size_t i = 0; i < resultTmp.size(); i++)
            {
                // 0 is upper, 1 is lower
                int mixedCase = util.GetRandom(0, 1);

                if (mixedCase == 0 && isalpha(resultTmp[i]))
                {
                    std::string push{resultTmp[i]};
                    result += util.ForceInputToCaseOf(push, ECLetterCase::uppercase);
                }
                else if (mixedCase == 1 && isalpha(resultTmp[i]))
                {
                    std::string push{resultTmp[i]};
                    result += util.ForceInputToCaseOf(push, ECLetterCase::lowercase);
                }
                else
                {
                    std::string push{resultTmp[i]};
                    result += push;
                }
            }
        }
        break;

        default:
        {
            result = util.ForceInputToCaseOf(resultTmp, ECLetterCase::uppercase);
        }
        break;
    }


    return result;
}








std::string prthgcpp::CCryptography::GeneratePasswordHasher(std::string input, const prthgcpp::ECCryptHasherMode passwordHasher, std::string salt) const
{
    std::string result;


    switch (passwordHasher)
    {
        case ECCryptHasherMode::SCRYPT:
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




std::string prthgcpp::CCryptography::StreamCipher(const prthgcpp::ECCryptCipherMode cipherMode, const prthgcpp::ECCryptStreamCipherMode streamCipherMode, std::string input, int initializeKey, int initializeVector,  std::string initializeKeyStr, std::string initializeVectorStr) const
{
    std::string result;
    std::string keyStr(initializeKeyStr), ivcStr(initializeVectorStr);


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
            else if (streamCipherMode == ECCryptStreamCipherMode::XChaCha20)
            {
                CryptoPP::HexEncoder encoder;
                // std::string tmp;
                // CryptoPP::HexEncoder encoder(new CryptoPP::StringSink(tmp));
                std::string plain(input), cipher;

                CryptoPP::SecByteBlock key((int)keyStr.size()), iv((int)ivcStr.size());

                encoder.Put(key.data(), key.size());
                encoder.MessageEnd();

                encoder.Put(iv.data(), iv.size());
                encoder.MessageEnd();

                CryptoPP::XChaCha20::Encryption enc;    
                enc.SetKeyWithIV(key, key.size(), iv, iv.size());

                CryptoPP::StringSource ss1(plain, true, new CryptoPP::StreamTransformationFilter(enc, new CryptoPP::StringSink(result)));

                encoder.Put((const CryptoPP::byte*)cipher.data(), cipher.size());
                encoder.MessageEnd();
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
            else if (streamCipherMode == ECCryptStreamCipherMode::XChaCha20)
            {
                CryptoPP::HexEncoder encoder;
                // std::string tmp;
                // CryptoPP::HexEncoder encoder(new CryptoPP::StringSink(tmp));
                std::string plain(input);

                CryptoPP::SecByteBlock key((int)keyStr.size()), iv((int)ivcStr.size());

                encoder.Put(key.data(), key.size());
                encoder.MessageEnd();

                encoder.Put(iv.data(), iv.size());
                encoder.MessageEnd();

                CryptoPP::XChaCha20::Decryption dec;    
                dec.SetKeyWithIV(key, key.size(), iv, iv.size());

                CryptoPP::StringSource ss2(plain, true, new CryptoPP::StreamTransformationFilter(dec, new CryptoPP::StringSink(result)));
            }
        }
        break;
    }


    return result;
}
