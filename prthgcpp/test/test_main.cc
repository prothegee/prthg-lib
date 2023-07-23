#include <prthgcpp/prthgcpp.h>


int main()
{
    prthgcpp::CUtility util;
    prthgcpp::CCryptography crypt;


    std::string emailInput = "foo@bar.baz";
    std::string secretMessage = "super secret message!";
    std::string rawPassword = "password123", saltPassword = "!supersalt123";


    // sha & blake
    std::cout << "SHA1:\n" << crypt.GenerateSHA1(emailInput) << "\n";
    std::cout << "SHA224:\n" << crypt.GenerateSHA224(emailInput) << "\n";
    std::cout << "SHA256:\n" << crypt.GenerateSHA256(emailInput) << "\n";
    std::cout << "SHA384:\n" << crypt.GenerateSHA384(emailInput) << "\n";
    std::cout << "SHA384:\n" << crypt.GenerateSHA384(emailInput) << "\n";
    std::cout << "SHA512:\n" << crypt.GenerateSHA512(emailInput) << "\n";
    std::cout << "BLAKE2b:\n" << crypt.GenerateBLAKE2b(emailInput) << "\n\n";


    // xchacha20
    std::string ikXChaCha20 = "abcdefghijklmnopqrstuvwxyz123456", ivXChaCha20 = "abcdefghijklmnopqrstuvwx";
    std::string encXChaCha20 = crypt.EncryptXChaCha20(secretMessage, ikXChaCha20, ivXChaCha20);
    std::string decXChaCha20 = crypt.DecryptXChaCha20(encXChaCha20, ikXChaCha20, ivXChaCha20);
    std::cout << "encXChaCha20:\n" << encXChaCha20 << "\n";
    std::cout << "decXChaCha20:\n" << decXChaCha20 << "\n\n";


    // cbc aes
    int ikCbcAes = 123456789, ivCbcAes = 987654321;
    std::string encCBCAES = crypt.EncryptCBCAES(secretMessage, ikCbcAes, ivCbcAes);
    std::string decCBCAES = crypt.DecryptCBCAES(encCBCAES, ikCbcAes, ivCbcAes);
    std::cout << "encCBCAES:\n" << encCBCAES << "\n";
    std::cout << "decCBCAES:\n" << decCBCAES << "\n\n";


    // scrypt
    std::string password = crypt.GenerateHasherSCRYPT(rawPassword, saltPassword);
    std::cout << "password:\n" << password << "\n\n";


    return 0;
}