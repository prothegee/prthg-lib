#include "prthgdf/LanguageContext.h"


prthgdf::CLanguageContext::CLanguageContext()
{
}

prthgdf::CLanguageContext::~CLanguageContext()
{
}








std::vector<std::string> prthgdf::CLanguageContext::SupportedLanguages()
{
    return m_supportedLanguages;
}








std::string prthgdf::CLanguageContext::HeaderAcceptLanguage(HttpRequestPtr pReq)
{
    return pReq->getHeader("Accept-Language");
}




std::string prthgdf::CLanguageContext::UserProcessingLanguage(HttpRequestPtr pReq)
{
    std::string retval{};
    std::string acceptLanguage(this->HeaderAcceptLanguage(pReq));


    for (auto language : m_supportedLanguages)
    {
        if (acceptLanguage.rfind(language, 0) == 0)
        {
            retval = language;
            break;
        }
        else
        {
            // default
            retval = "en";
        }
    }


    return retval;
}




void prthgdf::CLanguageContext::ForceDefaultLanguageRedirect(HttpResponsePtr pResp, const std::string language, std::function<void(const HttpResponsePtr &)> respCallback, const std::string redirectPath)
{
    bool valid{};


    for (auto languageCheck : m_supportedLanguages)
    {
        if (language == languageCheck)
        {
            valid = true;
        }
    }


    if (!valid)
    {
        pResp = HttpResponse::newHttpResponse();

        respCallback(pResp->newRedirectionResponse(redirectPath, k307TemporaryRedirect));
    }
}