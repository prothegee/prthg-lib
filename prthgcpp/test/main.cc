#include <prthgcpp/prthgcpp.h>


int main()
{
    int errorCount{0};


    prthgcpp::gsPtr->SayHello();


#pragma region cryptography
    prthgcpp::CCryptography crypt;

    std::cout << "(MSG) - testing cryptography" << "\n";

    std::string falseAlphanumInput = "myinput@somewhere.net";
    std::string trueAlphanumInput = "alphanumeric123456789"; 

    std::cout << "\n(MSG) - checking alphanum" << "\n";

    if (prthgcpp::gsPtr->pCryptography->InputIsAlphanumeric(falseAlphanumInput))
    {
        errorCount += 1;
        std::cout << "(ERR) - falseAlphanumInput should not alphanumeric\n";
    }
    if (!prthgcpp::gsPtr->pCryptography->InputIsAlphanumeric(trueAlphanumInput))
    {
        errorCount += 1;
        std::cout << "(ERR) - trueAlphanumInput should alphanumeric\n";
    }


    std::cout << "\n(MSG) - generate alphanum" << "\n";

    std::string alphanum1, alphanum2, alphanum3;
    srand(time(0));
    alphanum1 = crypt.GenerateAlphanumeric(8);
    alphanum2 = crypt.GenerateAlphanumeric(8);
    alphanum3 = crypt.GenerateAlphanumeric(8);

    std::cout << "alphanum1: " << alphanum1 << "\n";
    std::cout << "alphanum2: " << alphanum2 << "\n";
    std::cout << "alphanum3: " << alphanum3 << "\n\n";

    if (alphanum1 == alphanum2 || alphanum1 == alphanum3)
    {
        errorCount += 1;
        std::cout << "(ERR) - alphanum1 should not same with alphanum2 or alphanum3\n";
    }
    if (alphanum2 == alphanum1 || alphanum2 == alphanum3)
    {
        errorCount += 1;
        std::cout << "(ERR) - alphanum2 should not same with alphanum1 or alphanum3\n";
    }
    if (alphanum3 == alphanum1 || alphanum3 == alphanum2)
    {
        errorCount += 1;
        std::cout << "(ERR) - alphanum3 should not same with alphanum1 or alphanum2\n";
    }


    std::cout << "\n(MSG) - checking letter case" << "\n";
    std::string inputlowercase = "ajwdho326traiwbdoa8y3gr";
    std::string inputuppercase = "AIWLT2387TRAWHDP97Q3TRS";

    std::cout << inputlowercase << " to " << crypt.ForceInputToCaseOf(inputlowercase, prthgcpp::ECLetterCase::uppercase) << "\n";
    std::cout << inputuppercase << " to " << crypt.ForceInputToCaseOf(inputuppercase, prthgcpp::ECLetterCase::lowercase) << "\n";


    std::cout << "\n(MSG) - generate sha from unique@mail.com" << "\n";
    std::string inputSha = "unique@mail.com";

    std::string L40 = crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L40);
    std::cout << L40 << "\n";
    if (L40.length() != 40)
    {
        errorCount += 1;
        std::cout << "(ERR) - L40 length is not 40\n";
    }

    std::string L56 = crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L56);
    std::cout << L56 << "\n";
    if (L56.length() != 56)
    {
        errorCount += 1;
        std::cout << "(ERR) - L56 length is not 56\n";
    }

    std::string L64 = crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L64);
    std::cout << L64 << "\n";
    if (L64.length() != 64)
    {
        errorCount += 1;
        std::cout << "(ERR) - L64 length is not 64\n";
    }

    std::string L96 = crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L96);
    std::cout << L96 << "\n";
    if (L96.length() != 96)
    {
        errorCount += 1;
        std::cout << "(ERR) - L96 length is not 96\n";
    }

    std::string L128 = crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L128);
    std::cout << L128 << "\n";
    if (L128.length() != 128)
    {
        errorCount += 1;
        std::cout << "(ERR) - L128 length is not 128\n";
    }


    std::cout << "\n(MSG) - checking password hasher SCRYPT" << "\n";
    std::string password = "mypassword123", salt = "supersalt123", passwordHash, passwordCheck;
    passwordHash = crypt.GeneratePasswordHasher(password, prthgcpp::ECCryptPasswordHasher::SCRYPT, salt);
    passwordCheck = crypt.GeneratePasswordHasher(password, prthgcpp::ECCryptPasswordHasher::SCRYPT, salt);
    std::cout << "passwordHash:\n" << passwordHash << "\n\n";
    if (passwordHash != passwordCheck)
    {
        errorCount += 1;
        std::cout << "(ERR) - password is not match\n";
    }


    std::cout << "\n(MSG) - encrypt decrypt stream cipher" << "\n";
    std::string message = "secret message", messageEnc, messageDec;
    int ik = 123456789, iv = 987654321;
    messageEnc = crypt.StreamCipher(prthgcpp::ECCryptCipherMode::encrypt, prthgcpp::ECCryptStreamCipherMode::CBC_AES, message, ik, iv);
    messageDec = crypt.StreamCipher(prthgcpp::ECCryptCipherMode::decrypt, prthgcpp::ECCryptStreamCipherMode::CBC_AES, messageEnc, ik, iv);
    std::cout << "message: " << message << "\n";
    std::cout << "encrypt: " << messageEnc << "\n";
    std::cout << "decrypt: " << messageDec << "\n";
    if (messageDec != message)
    {
        errorCount += 1;
        std::cout << "(ERR) - decrypt fail\n";
    }
#pragma endregion


    std::cout << "\n(MSG) - error count: " << errorCount << "\n";


    return 0;
}