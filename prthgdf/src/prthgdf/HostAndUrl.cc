#include "prthgdf/HostAndUrl.h"
#include "prthgdf/prthgdf.h"


prthgdf::CHostAndUrl::CHostAndUrl(/* args */)
{
}

prthgdf::CHostAndUrl::~CHostAndUrl()
{
}








std::string prthgdf::CHostAndUrl::EHostSubdomainString(const EHostSubdomain hostSubdomain, const bool isStaging)
{
    std::string retval{};


    switch (hostSubdomain)
    {
        case eSubdomain_undefined:
            (!isStaging)
                ? retval = ""
                : retval = "staging.";
        break;

        case eSubdomain_account:
            (!isStaging)
                ? retval = "account."
                : retval = "staging-account.";
        break;

        case eSubdomain_admin:
            (!isStaging)
                ? retval = "admin."
                : retval = "staging-admin.";
        break;

        case eSubdomain_api:
            (!isStaging)
                ? retval = "api."
                : retval = "staging-api.";
        break;

        case eSubdomain_app:
            (!isStaging)
                ? retval = "app."
                : retval = "staging-app.";
        break;

        case eSubdomain_article:
            (!isStaging)
                ? retval = "article."
                : retval = "staging-article.";
        break;

        case eSubdomain_auth:
            (!isStaging)
                ? retval = "auth."
                : retval = "staging-auth.";
        break;

        case eSubdomain_blog:
            (!isStaging)
                ? retval = "blog."
                : retval = "staging-blog.";
        break;

        case eSubdomain_cdn:
            (!isStaging)
                ? retval = "cdn."
                : retval = "staging-cdn.";
        break;

        case eSubdomain_contact:
            (!isStaging)
                ? retval = "contact."
                : retval = "staging-contact.";
        break;

        case eSubdomain_dashboard:
            (!isStaging)
                ? retval = "dashboard."
                : retval = "staging-contact.";
        break;

        case eSubdomain_demo:
            (!isStaging)
                ? retval = "demo."
                : retval = "staging-demo.";
        break;

        case eSubdomain_docs:
            (!isStaging)
                ? retval = "docs."
                : retval = "staging-docs.";
        break;

        case eSubdomain_gallery:
            (!isStaging)
                ? retval = "gallery."
                : retval = "staging-gallery.";
        break;

        case eSubdomain_game:
            (!isStaging)
                ? retval = "game."
                : retval = "staging-game.";
        break;

        case eSubdomain_lnk:
            (!isStaging)
                ? retval = "lnk."
                : retval = "staging-lnk.";
        break;

        case eSubdomain_mail:
            (!isStaging)
                ? retval = "mail."
                : retval = "staging-mail.";
        break;

        case eSubdomain_music:
            (!isStaging)
                ? retval = "music."
                : retval = "staging-music.";
        break;

        case eSubdomain_nft:
            (!isStaging)
                ? retval = "nft."
                : retval = "staging-nft.";
        break;

        case eSubdomain_payment:
            (!isStaging)
                ? retval = "payment."
                : retval = "staging-payment.";
        break;

        case eSubdomain_play:
            (!isStaging)
                ? retval = "play."
                : retval = "staging-play.";
        break;

        case eSubdomain_project:
            (!isStaging)
                ? retval = "project."
                : retval = "staging-project.";
        break;

        case eSubdomain_public:
            (!isStaging)
                ? retval = "public."
                : retval = "staging-public.";
        break;

        case eSubdomain_shop:
            (!isStaging)
                ? retval = "shop."
                : retval = "staging-shop.";
        break;

        case eSubdomain_static:
            (!isStaging)
                ? retval = "static."
                : retval = "staging-static.";
        break;

        case eSubdomain_store:
            (!isStaging)
                ? retval = "store."
                : retval = "staging-store.";
        break;

        case eSubdomain_test:
            (!isStaging)
                ? retval = "test."
                : retval = "staging-test.";
        break;

        case eSubdomain_www:
            (!isStaging)
                ? retval = "www."
                : retval = "staging-www.";
        break;
    }


    return retval;
}




prthgdf::EHostSubdomain prthgdf::CHostAndUrl::EHostSubdomainEnum(const std::string hostHeader)
{
    EHostSubdomain retval = eSubdomain_undefined;


    if
    (
        hostHeader == "" + gPtr->EnvDomain()
        ||
        hostHeader == "staging." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_undefined;
    }


    if
    (
        hostHeader == "account." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-account." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_account;
    }


    if
    (
        hostHeader == "admin." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-admin." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_admin;
    }


    if
    (
        hostHeader == "api." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-api." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_api;
    }


    if
    (
        hostHeader == "app." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-app." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_app;
    }


    if
    (
        hostHeader == "article." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-article." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_article;
    }


    if
    (
        hostHeader == "auth." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-auth." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_auth;
    }


    if
    (
        hostHeader == "blog." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-blog." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_blog;
    }


    if
    (
        hostHeader == "cdn." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-cdn." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_cdn;
    }


    if
    (
        hostHeader == "contact." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-contact." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_contact;
    }


    if
    (
        hostHeader == "dashboard." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-dashboard." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_dashboard;
    }


    if
    (
        hostHeader == "demo." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-demo." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_demo;
    }


    if
    (
        hostHeader == "docs." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-docs." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_docs;
    }


    if
    (
        hostHeader == "gallery." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-gallery." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_gallery;
    }


    if
    (
        hostHeader == "game." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-game." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_game;
    }


    if
    (
        hostHeader == "lnk." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-lnk." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_lnk;
    }


    if
    (
        hostHeader == "mail." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-mail." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_mail;
    }


    if
    (
        hostHeader == "music." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-music." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_music;
    }


    if
    (
        hostHeader == "nft." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-nft." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_nft;
    }


    if
    (
        hostHeader == "payment." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-payment." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_payment;
    }


    if
    (
        hostHeader == "play." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-play." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_play;
    }


    if
    (
        hostHeader == "play." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-play." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_play;
    }


    if
    (
        hostHeader == "project." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-project." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_project;
    }


    if
    (
        hostHeader == "public." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-public." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_public;
    }


    if
    (
        hostHeader == "shop." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-shop." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_shop;
    }


    if
    (
        hostHeader == "static." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-static." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_static;
    }


    if
    (
        hostHeader == "store." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-store." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_store;
    }


    if
    (
        hostHeader == "test." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-test." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_test;
    }


    if
    (
        hostHeader == "www." + gPtr->EnvDomain()
        ||
        hostHeader == "staging-www." + gPtr->EnvDomain()
    )
    {
        retval = eSubdomain_www;
    }


    return retval;
}








std::string prthgdf::CHostAndUrl::HostName(const EHostSubdomain hostSubdomain)
{
    return EHostSubdomainString(hostSubdomain, gPtr->IsStaging()) + gPtr->EnvDomain();
}








std::string prthgdf::CHostAndUrl::Protocol(const EHostProtocol hostProtocol)
{
    std::string retval{};


    switch (hostProtocol)
    {
        case eProtocol_http:
            #if !NDEBUG
            retval = "http://";
            #else
            retval = "https://";
            #endif
        break;

        case eProtocol_ws:
            #if !NDEBUG
            retval = "ws://";
            #else
            retval = "wss://";
            #endif
        break;
    }


    return retval;
}