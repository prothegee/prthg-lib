#include "prthgdf/HostAndUrl.h"


prthgdf::CHostAndUrl::CHostAndUrl(/* args */)
{
}

prthgdf::CHostAndUrl::~CHostAndUrl()
{
}








std::string prthgdf::EHostSubdomainString(const EHostSubdomain hostSubdomain, const bool isStaging)
{
    std::string retval{};


    switch (hostSubdomain)
    {
        case eSubdomain_undefined:
            (!isStaging)
                ? retval = ""
                : retval = "staging";
        break;

        case eSubdomain_account:
            (!isStaging)
                ? retval = "account"
                : retval = "staging-account";
        break;

        case eSubdomain_admin:
            (!isStaging)
                ? retval = "admin"
                : retval = "staging-admin";
        break;

        case eSubdomain_app:
            (!isStaging)
                ? retval = "app"
                : retval = "staging-app";
        break;

        case eSubdomain_article:
            (!isStaging)
                ? retval = "article"
                : retval = "staging-article";
        break;

        case eSubdomain_auth:
            (!isStaging)
                ? retval = "auth"
                : retval = "staging-auth";
        break;

        case eSubdomain_blog:
            (!isStaging)
                ? retval = "blog"
                : retval = "staging-blog";
        break;

        case eSubdomain_cdn:
            (!isStaging)
                ? retval = "cdn"
                : retval = "staging-cdn";
        break;

        case eSubdomain_contact:
            (!isStaging)
                ? retval = "contact"
                : retval = "staging-contact";
        break;

        case eSubdomain_dashboard:
            (!isStaging)
                ? retval = "dashboard"
                : retval = "staging-contact";
        break;

        case eSubdomain_demo:
            (!isStaging)
                ? retval = "demo"
                : retval = "staging-demo";
        break;

        case eSubdomain_docs:
            (!isStaging)
                ? retval = "docs"
                : retval = "staging-docs";
        break;

        case eSubdomain_gallery:
            (!isStaging)
                ? retval = "gallery"
                : retval = "staging-gallery";
        break;

        case eSubdomain_game:
            (!isStaging)
                ? retval = "game"
                : retval = "staging-game";
        break;

        case eSubdomain_lnk:
            (!isStaging)
                ? retval = "lnk"
                : retval = "staging-lnk";
        break;

        case eSubdomain_mail:
            (!isStaging)
                ? retval = "mail"
                : retval = "staging-mail";
        break;

        case eSubdomain_music:
            (!isStaging)
                ? retval = "music"
                : retval = "staging-music";
        break;

        case eSubdomain_nft:
            (!isStaging)
                ? retval = "nft"
                : retval = "staging-nft";
        break;

        case eSubdomain_payment:
            (!isStaging)
                ? retval = "payment"
                : retval = "staging-payment";
        break;

        case eSubdomain_play:
            (!isStaging)
                ? retval = "play"
                : retval = "staging-play";
        break;

        case eSubdomain_project:
            (!isStaging)
                ? retval = "project"
                : retval = "staging-project";
        break;

        case eSubdomain_public:
            (!isStaging)
                ? retval = "public"
                : retval = "staging-public";
        break;

        case eSubdomain_shop:
            (!isStaging)
                ? retval = "shop"
                : retval = "staging-shop";
        break;

        case eSubdomain_static:
            (!isStaging)
                ? retval = "static"
                : retval = "staging-static";
        break;

        case eSubdomain_store:
            (!isStaging)
                ? retval = "store"
                : retval = "staging-store";
        break;

        case eSubdomain_test:
            (!isStaging)
                ? retval = "test"
                : retval = "staging-test";
        break;

        case eSubdomain_www:
            (!isStaging)
                ? retval = "www"
                : retval = "staging-www";
        break;
    }


    return retval;
}