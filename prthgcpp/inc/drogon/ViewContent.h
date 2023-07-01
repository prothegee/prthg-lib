/**
 * @file ViewContent.h
 * @author Prana Ron (prthg@proton.me)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
 */
#ifndef PRTHGCPP_DROGON_VIEW_CONTENT_H
#define PRTHGCPP_DROGON_VIEW_CONTENT_H
#include <drogon/drogon.h>


using namespace drogon;


namespace prthgcpp::drogon
{


    /**
     * @brief prthgcpp drogon view content class
     * 
     * @note commonly related with HttpViewData class and invoke it before the callback function
     * 
     */
    class CViewContent
    {
    private:
        /* data */


    public:
        CViewContent(/* args */);
        ~CViewContent();


        // shared public http view data property
        HttpViewData _view;


        /**
         * @brief invoke public/common view before callback
         * 
         * @param pReq 
         */
        void InvokePublicView(HttpRequestPtr& pReq);

        /**
         * @brief invoke css bulde to HttpViewData
         * 
         * @param bundleCss 
         */
        void InvokeBundleCSS(const std::string &bundleCss);

        /**
         * @brief invoke js bulde to HttpViewData
         * 
         * @param bundleJs 
         */
        void InvokeBundleJS(const std::string &bundleJs);
    };


} // namespace prthgcpp::drogon


#endif // PRTHGCPP_DROGON_VIEW_CONTENT_H