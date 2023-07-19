/**
 * @file ViewContent.h
 * @author Prana Ron (prothegee@protonmail.com)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prothegee@protonmail.com)
 * 
 */
#ifndef PRTHGCPP_DROGON_VIEW_CONTENT_H
#define PRTHGCPP_DROGON_VIEW_CONTENT_H
#include "prthgcpp/config.gen.h"


#ifdef __PRTHGCPP_INC_DROGON__
#include <drogon/drogon.h>


using namespace drogon;


namespace prthgcpp
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
         * @param bundleCss example: "/dist/bundle-www-home.css"
         */
        void InvokeBundleCSS(const std::string &bundleCss);

        /**
         * @brief invoke js bulde to HttpViewData
         * 
         * @param bundleCss example: "/dist/bundle-www-home.js"
         * 
         * @param bundleJs 
         */
        void InvokeBundleJS(const std::string &bundleJs);

        /**
         * @brief invoke language to HttpViewData
         * 
         * @param language 
         */
        void InvokeLanguage(const std::string &language);

        /**
         * @brief invoke message status to HttpViewData to BackendConst head tag
         * 
         * @param messageStatus 
         */
        void InvokeMessageStatus(const int &messageStatus);

        /**
         * @brief invoke message context to HttpViewData to BackendConst head tag
         * 
         * @param messageContext 
         */
        void InvokeMessageContext(const std::string  &messageContext);
    };


} // namespace prthgcpp


#endif // __PRTHGCPP_INC_DROGON__


#endif // PRTHGCPP_DROGON_VIEW_CONTENT_H