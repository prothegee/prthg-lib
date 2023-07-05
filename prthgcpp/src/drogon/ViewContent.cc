#include "prthgcpp/inc/drogon/ViewContent.h"


prthgcpp::drogon::CViewContent::CViewContent()
{
}

prthgcpp::drogon::CViewContent::~CViewContent()
{
}








void prthgcpp::drogon::CViewContent::InvokePublicView(HttpRequestPtr &pReq)
{
    // username
    std::string username;
    (pReq->session()->get<std::string>("username").length() <= 0)
        ? username = "guest"
        : username = pReq->session()->get<std::string>("username");
    _view.insert("username", username);
}




void prthgcpp::drogon::CViewContent::InvokeBundleCSS(const std::string &bundleCss)
{    
    std::string bundle;
    bundle += "<link rel='stylesheet' href='";
    bundle += bundleCss;
    bundle += "'>";


    _view.insert("bundle_css", bundle);
}




void prthgcpp::drogon::CViewContent::InvokeBundleJS(const std::string &bundleJs)
{
    std::string bundle;
    bundle += "<script defer src='";
    bundle += bundleJs;
    bundle += "'></script>";


    _view.insert("bundle_js", bundle);
}




void prthgcpp::drogon::CViewContent::InvokeLanguage(const std::string &language)
{
    _view.insert("language", language);
}