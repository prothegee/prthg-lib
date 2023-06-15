/**
 * @file prthgdf.h
 * @author Prana Ron (prothegee@protonmail.com)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prothegee@protonmail.com)
 * 
 */
#ifndef prthgdf_H
#define prthgdf_H
#include <drogon/drogon.h>

#include "prthgdf/HostAndUrl.h"

#include "prthgdf/LanguageContext.h"


namespace prthgdf
{
    class prthgdf::CHostAndUrl;

    class prthgdf::CLanguageContext;


    /**
     * @brief core/global prthgdf class
     * 
     */
    class CPrthgDf final
    {
    private:
        /* data */


    protected:
        /* data */


    public:
        CPrthgDf(/* args */);
        ~CPrthgDf();


        struct STools
        {
            static inline std::shared_ptr<prthgdf::CHostAndUrl> HostAndUrl = std::make_shared<prthgdf::CHostAndUrl>();
            static inline std::shared_ptr<prthgdf::CLanguageContext> LanguageContext = std::make_shared<prthgdf::CLanguageContext>();
        };
        // tools pointer access
        static inline std::shared_ptr<STools> pTools = std::make_shared<STools>();


        /**
         * @brief get int 420
         * 
         * @return int 
         */
        int Int420();

        /**
         * @brief get current status from custom_config of custom_config
         * 
         * @note list:
         * @note 0 = undefined
         * @note 1 = development
         * @note 2 = staging
         * @note 3 = production
         * 
         * @return int 
         */
        int Status();


        /**
         * @brief check if staging from custom_config of Status
         * 
         * @return true 
         * @return false 
         */
        bool IsStaging();


        std::string EnvDomain();
        std::string EnvProject();
        std::string EnvVersion();
    };


    // internal prthgdf global pointers access
    static inline std::shared_ptr<prthgdf::CPrthgDf> gPtr = std::make_shared<prthgdf::CPrthgDf>();


} // namespace prthgdf


#endif // prthgdf_H