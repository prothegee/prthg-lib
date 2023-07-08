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


    // protocol
    _view.insert("protocol", (app().getCustomConfig()["status"].asInt() == 1) ? "http://" : "https://");


    // roothost
    _view.insert("roothost", app().getCustomConfig()["roothost"].asString());


    // currentPath
    _view.insert("currentPath", pReq->getPath());


    // is_signedIn
    _view.insert("is_signedIn", (pReq->session()->get<bool>("is_signedIn")) ? "true" : "false");
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