/**
 * @file HostAndUrl.h
 * @author Prana Ron (prothegee@protonmail.com)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prothegee@protonmail.com)
 * 
 */
#ifndef PRTHGDF_DROGON_HOST_AND_URL_H
#define PRTHGDF_DROGON_HOST_AND_URL_H
#include <drogon/drogon.h>


using namespace drogon;


namespace prthgdf
{
    // enum constant for common host subdomain
    enum EHostSubdomain : int
    {
        eSubdomain_undefined = 0,   // eq: domain.tld
        eSubdomain_account,         // eq: account.domain.tld
        eSubdomain_admin,           // eq: admin.domain.tld
        eSubdomain_api,             // eq: api.domain.tld
        eSubdomain_app,             // eq: app.domain.tld
        eSubdomain_article,         // eq: article.domain.tld
        eSubdomain_auth,            // eq: auth.domain.tld
        eSubdomain_blog,            // eq: blog.domain.tld
        eSubdomain_cdn,             // eq: cdn.domain.tld
        eSubdomain_contact,         // eq: contact.domain.tld
        eSubdomain_dashboard,       // eq: dashboard.domain.tld
        eSubdomain_demo,            // eq: demo.domain.tld
        eSubdomain_docs,            // eq: docs.domain.tld
        eSubdomain_gallery,         // eq: gallery.domain.tld
        eSubdomain_game,            // eq: game.domain.tld
        eSubdomain_lnk,             // eq: lnk.domain.tld
        eSubdomain_mail,            // eq: mail.domain.tld
        eSubdomain_music,           // eq: music.domain.tld
        eSubdomain_nft,             // eq: nft.domain.tld
        eSubdomain_payment,         // eq: payment.domain.tld
        eSubdomain_play,            // eq: play.domain.tld
        eSubdomain_project,         // eq: project.domain.tld
        eSubdomain_public,          // eq: public.domain.tld
        eSubdomain_shop,            // eq: shop.domain.tld
        eSubdomain_static,          // eq: static.domain.tld
        eSubdomain_store,           // eq: store.domain.tld
        eSubdomain_test,            // eq: test.domain.tld
        eSubdomain_www,             // eq: www.domain.tld
    };


    enum EHostProtocol : int
    {
        eProtocol_undefined = 0,
        eProtocol_http,
        eProtocol_ws,
    };




    /**
     * @brief prthgdf backend drogonframework host and url class
     * 
     */
    class CHostAndUrl final
    {
    private:
        /* data */


    protected:
        /* data */


    public:
        CHostAndUrl(/* args */);
        ~CHostAndUrl();


        /**
         * @brief return string value convert from enum of EHostSubdomain
         * 
         * @note subdomain must a common as EHostSubdomain, otherwise use your own configuration
         * 
         * @param hostSubdomain 
         * @param isStaging 
         * @return std::string 
         */
        std::string EHostSubdomainString(const EHostSubdomain hostSubdomain, const bool isStaging);

        /**
         * @brief return enum value conver from host name header
         * 
         * @note subdomain must a common as EHostSubdomain, otherwise use your own configuration
         * 
         * @param hostHeader 
         * @return EHostSubdomain 
         */
        EHostSubdomain EHostSubdomainEnum(const std::string hostHeader);


        /**
         * @brief get default hostname based on 1st param
         * 
         * @note EnvDomain key required on custom_config
         * 
         * @param hostSubdomain 
         * @return std::string 
         */
        std::string HostName(const EHostSubdomain hostSubdomain);


        /**
         * @brief get default protocol
         * 
         * @note when NDEBUG will resulting secure (e.g. https:// or wss://)
         * 
         * @param hostProtocol 
         * @return std::string 
         */
        std::string Protocol(const EHostProtocol hostProtocol);
    };


} // namespace prthgdf


#endif // PRTHGDF_DROGON_HOST_AND_URL_H