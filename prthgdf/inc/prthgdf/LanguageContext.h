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
            "en",
            "id"
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


        /**
         * @brief get Accept-Language header
         * 
         * @param pReq 
         * @return std::string 
         */
        std::string HeaderAcceptLanguage(HttpRequestPtr pReq);


        /**
         * @brief process user language from supported languages
         * 
         * @param pReq 
         * @return std::string 
         */
        std::string UserProcessingLanguage(HttpRequestPtr pReq);


        void ForceDefaultLanguageRedirect(HttpResponsePtr pResp, const std::string language, std::function<void(const HttpResponsePtr &)> respCallback, const std::string redirectPath);
    };


} // namespace prthgdf


#endif // PRTHGDF_LANGUAGE_CONTEXT_H