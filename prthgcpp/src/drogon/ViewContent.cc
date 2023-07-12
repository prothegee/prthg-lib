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


    // jsessionid
    _view.insert("jsessionid", pReq->getCookie("JSESSIONID"));


    // roles
    std::vector<int> roles = pReq->session()->get<std::vector<int>>("roles");
    std::string rolesStr;
    for (const auto &role : roles)
    {
        rolesStr += (std::to_string(role) + ",");
    }
    _view.insert("roles", rolesStr);


    // rolesOrg
    std::vector<int> rolesOrg = pReq->session()->get<std::vector<int>>("rolesOrg");
    std::string rolesOrgStr;
    for (const auto &roleOrg : rolesOrgStr)
    {
        rolesOrgStr += (std::to_string(roleOrg) + ",");
    }
    _view.insert("rolesOrg", rolesOrg);


    // messageStatus :: default
    _view.insert("messageStatus", std::to_string(0));


    // messageContext :: default
    _view.insert("messageContext", "");
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




void prthgcpp::drogon::CViewContent::InvokeMessageStatus(const int &messageStatus)
{
    _view.insert("messageStatus", std::to_string(messageStatus));
}




void prthgcpp::drogon::CViewContent::InvokeMessageContext(const std::string &messageContext)
{
    _view.insert("messageStatus", messageContext);
}