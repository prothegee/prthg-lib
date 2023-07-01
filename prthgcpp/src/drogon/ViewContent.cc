#include "prthgcpp/inc/drogon/ViewContent.h"


prthgcpp::drogon::CViewContent::CViewContent()
{
}

prthgcpp::drogon::CViewContent::~CViewContent()
{
}








void prthgcpp::drogon::CViewContent::InvokePublicView(HttpRequestPtr &pReq)
{
    bool languageError{true};
    std::string language;
    const std::string acceptLanguage = pReq->getHeader("Accept-Language");
    const Json::Value supportedLanguage = app().getCustomConfig()["supported_languages"];

    for (auto& lang : supportedLanguage)
    {
        if (acceptLanguage.rfind(lang.asString(), 0) == 0)
        {
            language = lang.asString();
            languageError = false;
            break;
        }
    }
    
    if (languageError) { language = "en"; }
    
    
    _view.insert("language", language);
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


    _view.insert("bundle_css", bundle);
}