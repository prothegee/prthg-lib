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
    // enum constant for host subdomain
    enum EHostSubdomain : int
    {
        eSubdomain_undefined = 0,
        eSubdomain_account,
        eSubdomain_admin,
        eSubdomain_app,
        eSubdomain_article,
        eSubdomain_auth,
        eSubdomain_blog,
        eSubdomain_cdn,
        eSubdomain_contact,
        eSubdomain_dashboard,
        eSubdomain_demo,
        eSubdomain_docs,
        eSubdomain_gallery,
        eSubdomain_game,
        eSubdomain_lnk,
        eSubdomain_mail,
        eSubdomain_music,
        eSubdomain_nft,
        eSubdomain_payment,
        eSubdomain_play,
        eSubdomain_project,
        eSubdomain_public,
        eSubdomain_shop,
        eSubdomain_static,
        eSubdomain_store,
        eSubdomain_test,
        eSubdomain_www,
    };
    /**
     * @brief return string value convert from enum of EHostSubdomain
     * 
     * @param hostSubdomain 
     * @param isStaging 
     * @return std::string 
     */
    static std::string EHostSubdomainString(const EHostSubdomain hostSubdomain, const bool isStaging);




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
    };


} // namespace prthgdf


#endif // PRTHGDF_DROGON_HOST_AND_URL_H