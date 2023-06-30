/**
 * @file Utility.h
 * @author Prana Ron (prthg@proton.me)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
 */
#ifndef PRTHGCPP_UTILITY_H
#define PRTHGCPP_UTILITY_H
#include <string>
#include <algorithm>
#include <stdexcept>
#include <json/json.h>

#include "prthgcpp/inc/helpers/enums/LetterEnums.h"


namespace prthgcpp
{


    /**
     * @brief prthgcpp utility class
     * 
     */
    class CUtility
    {
    private:
        static inline const std::string m_base64Chars =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz"
            "0123456789+/";


    protected:
        /* data */


    public:
        CUtility(/* args */);
        ~CUtility();


        /**
         * @brief check if input is alphanumeric
         * 
         * @param input 
         * @return true 
         * @return false 
         */
        bool InputIsAlphanumeric(const std::string input) const;


        /**
         * @brief create json format from string input
         * 
         * @todo multiple json parser e.g. jsoncpp & nlohman-json?
         * 
         * @param input 
         * @return Json::Value 
         */
        Json::Value JsonFormatFromString(const std::string input) const;


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
    };


} // namespace prthgcpp


#endif // PRTHGCPP_UTILITY_H