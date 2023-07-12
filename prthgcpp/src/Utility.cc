#include "prthgcpp/inc/Utility.h"

#include <cstdlib>
#include <time.h>
#include <random>


prthgcpp::CUtility::CUtility()
{
}

prthgcpp::CUtility::~CUtility()
{
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








std::string prthgcpp::CUtility::GenerateAlphanumeric(int length) const
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
            result.reserve(input.size());

            for (int i = 0; i < input.length(); i++)
            {
                //  0 is upper, 1 is lower
                int mixedcase = GetRandom(0, 1);

                if (mixedcase == 0 && isalpha(input[i]))
                {
                    std::string push{input[i]};
                    result += ForceInputToCaseOf(push, ECLetterCase::uppercase);
                }
                else if (mixedcase == 1 && isalpha(input[i]))
                {
                    std::string push{input[i]};
                    result += ForceInputToCaseOf(push, ECLetterCase::lowercase);
                }
                else
                {
                    std::string push{input[i]};
                    result += push;
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








int prthgcpp::CUtility::GetRandom(const int &min, const int &max) const
{
    std::random_device rd;
    std::default_random_engine re(rd());
    std::uniform_int<int> distribute(min, max);

    return distribute(re);
}
double prthgcpp::CUtility::GetRandom(const double &min, const double &max) const
{
    std::random_device rd;
    std::default_random_engine re(rd());
    std::uniform_real<double> distribute(min, max);

    return distribute(re);
}