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

#include "prthgdf/LanguageContext.h"

#include "prthgdf/HostAndUrl.h"


namespace prthgdf
{
    class prthgdf::CLanguageContext;

    class prthgdf::CHostAndUrl;


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


        struct SBackend
        {
            std::shared_ptr<prthgdf::CLanguageContext> LanguageContext = nullptr;
        };
        // internal backend pointers access
        std::shared_ptr<SBackend> pBackend = nullptr;


        struct SDrogonFramework
        {
            std::shared_ptr<prthgdf::CHostAndUrl> HostAndUrl = nullptr;
        };
        // internal drogonframework pointers access
        std::shared_ptr<SDrogonFramework> pDrogonFramework = nullptr;


        int Int420();
    };


    // internal prthgdf global pointers access
    static inline std::shared_ptr<prthgdf::CPrthgDf> gPtrPrthgDf = std::make_shared<prthgdf::CPrthgDf>();


} // namespace prthgdf


#endif // prthgdf_H