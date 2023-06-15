/**
 * @file LanguageContext.h
 * @author Prana Ron (prothegee@protonmail.com)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prothegee@protonmail.com)
 * 
 */
#ifndef PRTHGDF_LANGUAGE_CONTEXT_H
#define PRTHGDF_LANGUAGE_CONTEXT_H
#include <drogon/drogon.h>


using namespace drogon;


namespace prthgdf
{


    /**
     * @brief drogonframework backend language context class
     * 
     * @note related to server/backend/frontend communication
     * 
     */
    class CLanguageContext
    {
    private:
        const std::vector<std::string> m_supportedLanguages = {
            "id",
            "en"
        };


    protected:
        /* data */


    public:
        CLanguageContext(/* args */);
        ~CLanguageContext();


        /**
         * @brief get current backend supported languages
         * 
         * @note availability:
         * @note - id ( default Bahasa )
         * @note - en ( default English )
         * 
         * @return std::vector<std::string> 
         */
        std::vector<std::string> SupportedLanguages();
    };


} // namespace prthgdf


#endif // PRTHGDF_LANGUAGE_CONTEXT_H