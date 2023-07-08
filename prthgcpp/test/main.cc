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

    if (prthgcpp::gsPtr->pUtility->InputIsAlphanumeric(falseAlphanumInput))
    {
        errorCount += 1;
        std::cout << "(ERR) - falseAlphanumInput should not alphanumeric\n";
    }
    if (!prthgcpp::gsPtr->pUtility->InputIsAlphanumeric(trueAlphanumInput))
    {
        errorCount += 1;
        std::cout << "(ERR) - trueAlphanumInput should alphanumeric\n";
    }


    std::cout << "\n(MSG) - generate alphanum" << "\n";

    std::string alphanum1, alphanum2, alphanum3;
    srand(time(0));
    alphanum1 = prthgcpp::gsPtr->pUtility->GenerateAlphanumeric(8);
    alphanum2 = prthgcpp::gsPtr->pUtility->GenerateAlphanumeric(8);
    alphanum3 = prthgcpp::gsPtr->pUtility->GenerateAlphanumeric(8);

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

    std::cout << inputlowercase << " to " << prthgcpp::gsPtr->pUtility->ForceInputToCaseOf(inputlowercase, prthgcpp::ECLetterCase::uppercase) << "\n";
    std::cout << inputuppercase << " to " << prthgcpp::gsPtr->pUtility->ForceInputToCaseOf(inputuppercase, prthgcpp::ECLetterCase::lowercase) << "\n";


    std::cout << "\n(MSG) - generate sha from unique@mail.com" << "\n";
    std::string inputSha = "unique@mail.com";

    std::string L40 = crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L40, false);
    std::cout << L40 << "\n";
    std::cout << crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L40, true) << "\n\n";
    if (L40.length() != 40)
    {
        errorCount += 1;
        std::cout << "(ERR) - L40 length is not 40\n";
    }

    std::string L56 = crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L56, false);
    std::cout << L56 << "\n";
    std::cout << crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L56, true) << "\n\n";
    if (L56.length() != 56)
    {
        errorCount += 1;
        std::cout << "(ERR) - L56 length is not 56\n";
    }

    std::string L64 = crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L64, false);
    std::cout << L64 << "\n";
    std::cout << crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L64, true) << "\n\n";
    if (L64.length() != 64)
    {
        errorCount += 1;
        std::cout << "(ERR) - L64 length is not 64\n";
    }

    std::string L96 = crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L96, false);
    std::cout << L96 << "\n";
    std::cout << crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L96, true) << "\n\n";
    if (L96.length() != 96)
    {
        errorCount += 1;
        std::cout << "(ERR) - L96 length is not 96\n";
    }

    std::string L128 = crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L128, false);
    std::cout << L128 << "\n";
    std::cout << crypt.GenerateSHA(inputSha, prthgcpp::ECCryptShaLength::L128, true) << "\n\n";
    if (L128.length() != 128)
    {
        errorCount += 1;
        std::cout << "(ERR) - L128 length is not 128\n";
    }


    std::cout << "\n(MSG) - generate blake2b from unique@mail.com" << "\n";
    std::cout << crypt.GenerateBLAKE2b(inputSha, false) << "\n";
    std::cout << crypt.GenerateBLAKE2b(inputSha, true) << "\n";


    std::cout << "\n(MSG) - checking password hasher SCRYPT" << "\n";
    std::string password = "mypassword123", salt = "supersalt123", passwordHash, passwordCheck;
    passwordHash = crypt.GeneratePasswordHasher(password, prthgcpp::ECCryptHasherMode::SCRYPT, salt);
    passwordCheck = crypt.GeneratePasswordHasher(password, prthgcpp::ECCryptHasherMode::SCRYPT, salt);
    std::cout << "passwordHash:\n" << passwordHash << "\n\n";
    std::cout << "passwordCheck:\n" << passwordCheck << "\n\n";
    if (passwordHash != passwordCheck)
    {
        errorCount += 1;
        std::cout << "(ERR) - password is not match\n";
    }


    int ik = 123456789, iv = 987654321;
    std::string iks = "abcdefghijklmnopqrstuvwxyz123456", ivs = "abcdefghijklmnopqrstuvwx";

    std::cout << "\n(MSG) - encrypt decrypt stream cipher CBC_AES" << "\n";
    
    std::string message1 = "secret message 1", messageEnc1, messageDec1;
    {
        messageEnc1 = crypt.StreamCipher(prthgcpp::ECCryptCipherMode::encrypt, prthgcpp::ECCryptStreamCipherMode::CBC_AES, message1, ik, iv, iks, ivs);
        messageDec1 = crypt.StreamCipher(prthgcpp::ECCryptCipherMode::decrypt, prthgcpp::ECCryptStreamCipherMode::CBC_AES, messageEnc1, ik, iv, iks, ivs);
        std::cout << message1 << "\n";
        std::cout << messageEnc1 << "\n";
        std::cout << messageDec1 << "\n";
        if (messageDec1 != message1)
        {
            errorCount += 1;
            std::cout << "(ERR) - decrypt fail CBC_AES\n";
        }
    }


    std::cout << "\n(MSG) - encrypt decrypt stream cipher XChaCha20" << "\n";
    std::string message2 = "secret message 2", messageEnc2, messageDec2;
    {
        messageEnc2 = crypt.StreamCipher(prthgcpp::ECCryptCipherMode::encrypt, prthgcpp::ECCryptStreamCipherMode::XChaCha20, message2, ik, iv, iks, ivs);
        messageDec2 = crypt.StreamCipher(prthgcpp::ECCryptCipherMode::decrypt, prthgcpp::ECCryptStreamCipherMode::XChaCha20, messageEnc2, ik, iv, iks, ivs);
        std::cout << message2 << "\n";
        std::cout << messageEnc2 << "\n";
        std::cout << messageDec2 << "\n";
        if (messageDec2 != message2)
        {
            errorCount += 1;
            std::cout << "(ERR) - decrypt fail XChaCha20\n";
        }
    }
#pragma endregion


    std::cout << "\n(MSG) - error count: " << errorCount << "\n";


    return 0;
}