#include "prthgcpp/inc/Utility.h"


prthgcpp::CUtility::CUtility()
{
}

prthgcpp::CUtility::~CUtility()
{
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
    }


    return result;
}