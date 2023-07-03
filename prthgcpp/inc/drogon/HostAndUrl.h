/**
 * @file HostAndUrl.h
 * @author Prana Ron (prthg@proton.me)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
 */
#ifndef PRTHGCPP_DROGON_HOST_AND_URL_H
#define PRTHGCPP_DROGON_HOST_AND_URL_H
#include <drogon/drogon.h>


using namespace drogon;


namespace prthgcpp::drogon
{
    #if _WIN32
        #pragma warning (disable: 4114) // same type qualifier used more than once
    #else
        // what?
    #endif


    /**
     * @brief host and url backend integration
     * 
     */
    class CHostAndUrl
    {
    private:
        /* data */


    protected:
        /* data */


    public:
        CHostAndUrl(/* args */);
        ~CHostAndUrl();


        /**
         * @brief check current request origin is allowed from whitelist
         * 
         * @param pReq 
         * @param whitelistDomain 
         * @return true 
         * @return false 
         */
        bool CheckOriginToAllowAccess(HttpRequestPtr pReq, Json::Value whitelistDomain);


        /**
         * @brief check current request origin is allowed from whitelist
         * 
         * @note coroutine
         * 
         * @param pReq 
         * @param whitelistDomain 
         * @return Task<bool> 
         */
        Task<bool> CheckOriginToAllowAccessTask(HttpRequestPtr pReq, Json::Value whitelistDomain);


        /**
         * @brief check current request host header is in allowedHost, otherwise it's not acceptable
         * 
         * @param pReq 
         * @param allowedHost 
         * @param pResp 
         * @param callback 
         */
        void EvaluateHostIsAllowed(HttpRequestPtr pReq, const std::string allowedHost, HttpResponsePtr pResp, std::function<void(const HttpResponsePtr &)> callback);

        /**
         * @brief check current request host header is in allowedHost vector string, otherwise it's not acceptable
         * 
         * @param pReq 
         * @param allowedHosts 
         * @param pResp 
         * @param callback 
         */
        void EvaluateHostsIsAllowed(HttpRequestPtr pReq, const std::vector<std::string> allowedHosts, HttpResponsePtr pResp, std::function<void(const HttpResponsePtr &)> callback);


        /**
         * @brief check current request host header is in allowedHost, otherwise it's not acceptable
         * 
         * @note coroutine
         * 
         * @param pReq 
         * @param allowedHost 
         * @param pResp 
         * @param callback 
         * @return Task<void> 
         */
        Task<void> EvaluateHostIsAllowedTask(HttpRequestPtr pReq, const std::string allowedHost, HttpResponsePtr pResp, std::function<void(const HttpResponsePtr &)> callback);

        /**
         * @brief check current request host header is in allowedHost vector string, otherwise it's not acceptable
         * 
         * @note coroutine
         * 
         * @param pReq 
         * @param allowedHosts 
         * @param pResp 
         * @param callback 
         * @return Task<void> 
         */
        Task<void> EvaluateHostsIsAllowedTask(HttpRequestPtr pReq, const const std::vector<std::string> allowedHosts, HttpResponsePtr pResp, std::function<void(const HttpResponsePtr &)> callback);


        /**
         * @brief check origin header is allowed from whitelist json custom_config 'foo: [...]'
         *  
         * @param pReq 
         * @param whitelist 
         * @return true 
         * @return false 
         */
        bool EvaluateOriginIsAllowed(HttpRequestPtr pReq, Json::Value whitelist) const;


        /**
         * @brief check origin header is allowed from whitelist json custom_config 'foo: [...]'
         * 
         * @note coroutine
         * 
         * @param pReq 
         * @param whitelist 
         * @return Task<bool> 
         */
        Task<bool> EvaluateOriginIsAllowedTask(HttpRequestPtr pReq, Json::Value whitelist) const;
    };


} // namespace prthgcpp::drogon

#endif // PRTHGCPP_DROGON_HOST_AND_URL_H