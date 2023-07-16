#include "prthgcpp/inc/drogon/ViewContent.h"


prthgcpp::CViewContent::CViewContent()
{
}

prthgcpp::CViewContent::~CViewContent()
{
}








void prthgcpp::CViewContent::InvokePublicView(HttpRequestPtr &pReq)
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




void prthgcpp::CViewContent::InvokeBundleCSS(const std::string &bundleCss)
{    
    std::string bundle;
    bundle += "<link rel='stylesheet' href='";
    bundle += bundleCss;
    bundle += "'>";


    _view.insert("bundle_css", bundle);
}




void prthgcpp::CViewContent::InvokeBundleJS(const std::string &bundleJs)
{
    std::string bundle;
    bundle += "<script defer src='";
    bundle += bundleJs;
    bundle += "'></script>";


    _view.insert("bundle_js", bundle);
}




void prthgcpp::CViewContent::InvokeLanguage(const std::string &language)
{
    _view.insert("language", language);
}




void prthgcpp::CViewContent::InvokeMessageStatus(const int &messageStatus)
{
    _view.insert("messageStatus", std::to_string(messageStatus));
}




void prthgcpp::CViewContent::InvokeMessageContext(const std::string &messageContext)
{
    _view.insert("messageStatus", messageContext);
}