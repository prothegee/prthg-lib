#include "prthgcpp/inc/drogon/ViewContent.h"


prthgcpp::drogonframework::CViewContent::CViewContent()
{
}

prthgcpp::drogonframework::CViewContent::~CViewContent()
{
}








void prthgcpp::drogonframework::CViewContent::InvokePublicView(HttpRequestPtr &pReq)
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


    // jsessionid
    _view.insert("jsessionid", pReq->getCookie("JSESSIONID"));


    // messageStatus :: default
    _view.insert("messageStatus", std::to_string(0));


    // messageContext :: default
    _view.insert("messageContext", "");
}




void prthgcpp::drogonframework::CViewContent::InvokeBundleCSS(const std::string &bundleCss)
{    
    std::string bundle;
    bundle += "<link rel='stylesheet' href='";
    bundle += bundleCss;
    bundle += "'>";


    _view.insert("bundle_css", bundle);
}




void prthgcpp::drogonframework::CViewContent::InvokeBundleJS(const std::string &bundleJs)
{
    std::string bundle;
    bundle += "<script defer src='";
    bundle += bundleJs;
    bundle += "'></script>";


    _view.insert("bundle_js", bundle);
}




void prthgcpp::drogonframework::CViewContent::InvokeLanguage(const std::string &language)
{
    _view.insert("language", language);
}




void prthgcpp::drogonframework::CViewContent::InvokeMessageStatus(const int &messageStatus)
{
    _view.insert("messageStatus", std::to_string(messageStatus));
}




void prthgcpp::drogonframework::CViewContent::InvokeMessageContext(const std::string &messageContext)
{
    _view.insert("messageStatus", messageContext);
}