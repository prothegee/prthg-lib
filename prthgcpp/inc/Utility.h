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
#include <json/json.h>


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
         * @brief create json format from string input
         * 
         * @todo multiple json parser e.g. jsoncpp & nlohman-json?
         * 
         * @param input 
         * @return Json::Value 
         */
        Json::Value JsonFormatFromString(const std::string input) const;
    };


} // namespace prthgcpp


#endif // PRTHGCPP_UTILITY_H