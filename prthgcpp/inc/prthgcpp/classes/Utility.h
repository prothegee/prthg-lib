/**
 * @file Utility.h
 * @author Prana Ron (prothegee@protonmail.com)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prothegee@protonmail.com)
 * 
 */
#ifndef PRTHGCPP_UTILITY_H
#define PRTHGCPP_UTILITY_H
#include "prthgcpp/config.gen.h"

#include <string>
#include <cctype>
#include <algorithm>
#include <stdexcept>

#ifdef __INC_PRTHGCPP_JSONCPP__
    #include <json/json.h>
#endif // __INC_PRTHGCPP_JSONCPP__

#include "prthgcpp/enums/LetterEnums.h"


namespace prthgcpp
{


    /**
     * @brief prthgcpp utility class
     * 
     */
    class CUtility
    {
    private:
        /* data */


    protected:
        /* data */


    public:
        CUtility(/* args */);
        ~CUtility();


        /**
         * @brief check if input is only alphabetic
         * 
         * @param input 
         * @return true 
         * @return false 
         */
        bool InputIsAlphabethic(const std::string input) const;


        /**
         * @brief check if input is only alphanumeric
         * 
         * @param input 
         * @return true 
         * @return false 
         */
        bool InputIsAlphanumeric(const std::string input) const;


        /**
         * @brief generate alphanumeric based on length param
         * 
         * @note length less than 4 will be set to 4
         * @note this generator quality is average
         * @note you need add srand(time(0)) before call this function
         * 
         * @param length 
         * @return std::string 
         */
        std::string GenerateAlphanumeric(int length) const;

        /**
         * @brief force input as letterCase param format
         * 
         * @param input 
         * @param letterCase 
         * @return std::string 
         */
        std::string ForceInputToCaseOf(std::string input, const prthgcpp::ECLetterCase letterCase) const;


        int GetRandom(const int &min, const int &max) const;
        double GetRandom(const double &min, const double &max) const;


        #ifdef __INC_PRTHGCPP_JSONCPP__
        /**
         * @brief create json format from string input
         * 
         * @param input 
         * @return Json::Value 
         */
        Json::Value JsonFormatFromString(const std::string input) const;

        /**
         * @brief create string from json value input
         * 
         * @param json 
         * @return std::string 
         */
        std::string StringFormatFromJsonValue(const Json::Value json) const;
        #endif // __INC_PRTHGCPP_JSONCPP__
    };


} // namespace prthgcpp

#endif // PRTHGCPP_UTILITY_H