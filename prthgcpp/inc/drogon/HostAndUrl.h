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
    };


} // namespace prthgcpp::drogon

#endif // PRTHGCPP_DROGON_HOST_AND_URL_H