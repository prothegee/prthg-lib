#include "prthgcpp/classes/Utility.h"

#include <cstdlib>
#include <time.h>
#include <random>


prthgcpp::CUtility::CUtility()
{
}

prthgcpp::CUtility::~CUtility()
{
}








std::string prthgcpp::CUtility::GetAlphaNumeric() const
{
    return m_alphanum;
}








bool prthgcpp::CUtility::InputIsAlphabethic(const std::string input) const
{
    auto itter = std::find_if(input.begin(), input.end(), [](char const& c)
    {
        return !isalpha(c);
    });

    return itter == input.end();
}








bool prthgcpp::CUtility::InputIsAlphanumeric(const std::string input) const
{
    auto itter = std::find_if(input.begin(), input.end(), [](char const& c)
    {
        return !isalnum(c);
    });

    return itter == input.end();
}








std::string prthgcpp::CUtility::GenerateAlphanumeric(int length) const
{
    std::string result;


    if (length <= 0) { length = 1; }

    result.reserve(length);

    for (int i = 0; i < length; i++)
    {
        int j = GetRandomNumber(0, m_alphanum.length()-1);
        result += m_alphanum[j];
    }


    return result;
}








std::string prthgcpp::CUtility::ForceInputToCaseOf(std::string input, const prthgcpp::ECLetterCase letterCase) const
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


        case ECLetterCase::mixedcase:
        {
            for (int i = 0; i < input.length(); i++)
            {
                //  0 is lower, 1 is upper
                int mixedcase = GetRandomNumber(0, 1);

                if (mixedcase == 0 && isalpha(input[i]))
                {
                    result += tolower(input[i]);
                }
                else if (mixedcase == 1 && isalpha(input[i]))
                {
                    result += toupper(input[i]);
                }
                else
                {
                    result += input[i];
                }
            }
        }
        break;


        default:
        {
            result = input;
        }
        break;
    }


    return result;
}

std::string prthgcpp::CUtility::ForceInputToCaseOf(std::string input, const int &letterCase) const
{
    std::string result;


    result.reserve(input.length());

    switch (letterCase)
    {
        case 0:
        {
            for (int i = 0; i < input.length(); i++)
            {
                result += tolower(input[i]);
            }
        }
        break;


        case 1:
        {
            for (int i = 0; i < input.length(); i++)
            {
                result += toupper(input[i]);
            }
        }
        break;


        case 2:
        {
            for (int i = 0; i < input.length(); i++)
            {
                //  0 is lower, 1 is upper
                int mixedcase = GetRandomNumber(0, 1);

                if (mixedcase == 0 && isalpha(input[i]))
                {
                    result += tolower(input[i]);
                }
                else if (mixedcase == 1 && isalpha(input[i]))
                {
                    result += toupper(input[i]);
                }
                else
                {
                    result += input[i];
                }
            }
        }
        break;


        default:
        {
            result = input;
        }
        break;
    }


    return result;
}








int prthgcpp::CUtility::GetRandomNumber(const int &min, const int &max) const
{
    std::random_device rd;
    std::default_random_engine re(rd());
    std::uniform_int<int> distribute(min, max);

    return distribute(re);
}
double prthgcpp::CUtility::GetRandomNumber(const double &min, const double &max) const
{
    std::random_device rd;
    std::default_random_engine re(rd());
    std::uniform_real<double> distribute(min, max);

    return distribute(re);
}








#ifdef __INC_PRTHGCPP_JSONCPP__
Json::Value prthgcpp::CUtility::JsonFormatFromString(const std::string input) const
{
    Json::Value result;


    JSONCPP_STRING err;
    Json::CharReaderBuilder builder;
    const int inputLength = static_cast<int>(input.length());

    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    reader->parse(input.c_str(), input.c_str() + inputLength, &result, &err);


    return result;
}





std::string prthgcpp::CUtility::StringFormatFromJsonValue(const Json::Value json) const
{
    std::string result;

    Json::StreamWriterBuilder builder;
    result = Json::writeString(builder, json);

    return result;
}
#endif // __INC_PRTHGCPP_JSONCPP__








std::string prthgcpp::CUtility::GenerateUUID() const
{
    std::string result;
    std::string str1(GenerateAlphanumeric(8)), str2(GenerateAlphanumeric(4)), str3(GenerateAlphanumeric(4)), str4(GenerateAlphanumeric(4)), str5(GenerateAlphanumeric(12));

    result = str1 + "-" + str2 + "-" + str3 + "-" + str4 + "-" + str5;

    return result;
}