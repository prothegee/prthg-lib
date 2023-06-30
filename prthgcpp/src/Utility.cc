#include "prthgcpp/inc/Utility.h"


prthgcpp::CUtility::CUtility()
{
}

prthgcpp::CUtility::~CUtility()
{
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
