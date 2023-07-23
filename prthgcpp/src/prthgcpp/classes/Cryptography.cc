#include "prthgcpp/classes/Cryptography.h"


#ifdef __INC_PRTHGCPP_CRYPTOPP__
prthgcpp::CCryptography::CCryptography()
{
}

prthgcpp::CCryptography::~CCryptography()
{
}








std::string prthgcpp::CCryptography::GenerateSHA1(const std::string &input) const
{
    std::string result;

    CryptoPP::SHA1 hash;
    CryptoPP::byte digest[CryptoPP::SHA1::DIGESTSIZE];
    CryptoPP::HexEncoder encoder;

    hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

    encoder.Attach(new CryptoPP::StringSink(result));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    return result;
}

std::string prthgcpp::CCryptography::GenerateSHA224(const std::string &input) const
{
    std::string result;

    CryptoPP::SHA224 hash;
    CryptoPP::byte digest[CryptoPP::SHA224::DIGESTSIZE];
    CryptoPP::HexEncoder encoder;

    hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

    encoder.Attach(new CryptoPP::StringSink(result));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    return result;
}

std::string prthgcpp::CCryptography::GenerateSHA256(const std::string &input) const
{
    std::string result;

    CryptoPP::SHA256 hash;
    CryptoPP::byte digest[CryptoPP::SHA256::DIGESTSIZE];
    CryptoPP::HexEncoder encoder;

    hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

    encoder.Attach(new CryptoPP::StringSink(result));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    return result;
}

std::string prthgcpp::CCryptography::GenerateSHA384(const std::string &input) const
{
    std::string result;

    CryptoPP::SHA384 hash;
    CryptoPP::byte digest[CryptoPP::SHA384::DIGESTSIZE];
    CryptoPP::HexEncoder encoder;

    hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

    encoder.Attach(new CryptoPP::StringSink(result));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    return result;
}

std::string prthgcpp::CCryptography::GenerateSHA512(const std::string &input) const
{
    std::string result;

    CryptoPP::SHA512 hash;
    CryptoPP::byte digest[CryptoPP::SHA512::DIGESTSIZE];
    CryptoPP::HexEncoder encoder;

    hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

    encoder.Attach(new CryptoPP::StringSink(result));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    return result;
}








std::string prthgcpp::CCryptography::GenerateBLAKE2b(const std::string &input) const
{
    std::string result;

    CryptoPP::BLAKE2b hash;
    CryptoPP::byte digest[CryptoPP::BLAKE2b::DIGESTSIZE];
    CryptoPP::HexEncoder encoder;

    hash.CalculateDigest(digest, (CryptoPP::byte*)input.c_str(), input.length());

    encoder.Attach(new CryptoPP::StringSink(result));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    return result;
}








std::string prthgcpp::CCryptography::GenerateHasherSCRYPT(std::string input, std::string salt) const
{
    std::string result;

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

    return result;
}








std::string prthgcpp::CCryptography::EncryptXChaCha20(std::string input, std::string initializeKey, std::string initializeVector) const
{
    std::string result;

    CryptoPP::HexEncoder encoder;
    std::string plain(input), cipher;

    CryptoPP::SecByteBlock key((int)initializeKey.size()), iv((int)initializeVector.size());

    encoder.Put(key.data(), key.size());
    encoder.MessageEnd();

    encoder.Put(iv.data(), iv.size());
    encoder.MessageEnd();

    CryptoPP::XChaCha20::Encryption enc;    
    enc.SetKeyWithIV(key, key.size(), iv, iv.size());

    CryptoPP::StringSource ss1(plain, true, new CryptoPP::StreamTransformationFilter(enc, new CryptoPP::StringSink(result)));

    encoder.Put((const CryptoPP::byte*)cipher.data(), cipher.size());
    encoder.MessageEnd();

    return result;
}

std::string prthgcpp::CCryptography::DecryptXChaCha20(std::string input, std::string initializeKey, std::string initializeVector) const
{
    std::string result;

    CryptoPP::HexEncoder encoder;
    std::string plain(input);

    CryptoPP::SecByteBlock key((int)initializeKey.size()), iv((int)initializeVector.size());

    encoder.Put(key.data(), key.size());
    encoder.MessageEnd();

    encoder.Put(iv.data(), iv.size());
    encoder.MessageEnd();

    CryptoPP::XChaCha20::Decryption dec;    
    dec.SetKeyWithIV(key, key.size(), iv, iv.size());

    CryptoPP::StringSource ss2(plain, true, new CryptoPP::StreamTransformationFilter(dec, new CryptoPP::StringSink(result)));

    return result;
}








std::string prthgcpp::CCryptography::EncryptCBCAES(std::string input, int initializeKey, int initializeVector) const
{
    std::string result;

    CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];
    memset(key, initializeKey, CryptoPP::AES::DEFAULT_KEYLENGTH);
    memset(iv, initializeVector, CryptoPP::AES::BLOCKSIZE);

    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);

    CryptoPP::StreamTransformationFilter encrypt(cbcEncryption, new CryptoPP::StringSink(result));
    encrypt.Put(reinterpret_cast<const unsigned char*>(input.c_str()), input.length());
    encrypt.MessageEnd();

    return result;
}

std::string prthgcpp::CCryptography::DecryptCBCAES(std::string input, int initializeKey, int initializeVector) const
{
    std::string result;

    CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];
    memset(key, initializeKey, CryptoPP::AES::DEFAULT_KEYLENGTH);
    memset(iv, initializeVector, CryptoPP::AES::BLOCKSIZE);

    CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);

    CryptoPP::StreamTransformationFilter decrypt(cbcDecryption, new CryptoPP::StringSink(result));
    decrypt.Put(reinterpret_cast<const unsigned char*>( input.c_str() ), input.size());
    decrypt.MessageEnd();

    return result;
}
#endif // __INC_PRTHGCPP_CRYPTOPP__