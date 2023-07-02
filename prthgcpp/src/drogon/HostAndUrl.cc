#include "prthgcpp/inc/drogon/HostAndUrl.h"

#include <type_traits>


prthgcpp::drogon::CHostAndUrl::CHostAndUrl()
{
}

prthgcpp::drogon::CHostAndUrl::~CHostAndUrl()
{
}








bool prthgcpp::drogon::CHostAndUrl::CheckOriginToAllowAccess(HttpRequestPtr pReq, Json::Value whitelistDomain)
{
    bool result{};

    for (auto host : whitelistDomain)
    {
        if (host.asString().rfind(pReq->getHeader("origin"), 0) == 0)
        {
            result = true;
            break;
        }
    }

    return result;
}


Task<bool> prthgcpp::drogon::CHostAndUrl::CheckOriginToAllowAccessTask(HttpRequestPtr pReq, Json::Value whitelistDomain)
{
    bool result{};

    for (auto host : whitelistDomain)
    {
        if (host.asString().rfind(pReq->getHeader("origin"), 0) == 0)
        {
            result = true;
            break;
        }
    }

    co_return result;
}








void prthgcpp::drogon::CHostAndUrl::EvaluateHostIsAllowed(HttpRequestPtr pReq, const std::string allowedHost, HttpResponsePtr pResp, std::function<void(const HttpResponsePtr &)> callback)
{
    bool result{};


    if (allowedHost.rfind(pReq->getHeader("host"), 0) == 0)
    {
        result = true;
    }

    if (!result)
    {
        pResp = HttpResponse::newHttpResponse();
        pResp->setStatusCode(k406NotAcceptable);

        callback(pResp);
    }
}




Task<void> prthgcpp::drogon::CHostAndUrl::EvaluateHostIsAllowedTask(HttpRequestPtr pReq, const std::string allowedHost, HttpResponsePtr pResp, std::function<void(const HttpResponsePtr &)> callback)
{
    bool result{};


    if (allowedHost.rfind(pReq->getHeader("host"), 0) == 0)
    {
        result = true;
    }

    if (!result)
    {
        pResp = HttpResponse::newHttpResponse();
        pResp->setStatusCode(k406NotAcceptable);

        callback(pResp);
    }

    co_return; // seems not right?
}








bool prthgcpp::drogon::CHostAndUrl::EvaluateOriginIsAllowed(HttpRequestPtr pReq, Json::Value whitelist) const
{
    bool result{};


    for (auto host : whitelist)
    {
        if (host.asString().rfind(pReq->getHeader("origin"), 0) == 0)
        {
            result = true;
            break;
        }
    }


    return result;
}




Task<bool> prthgcpp::drogon::CHostAndUrl::EvaluateOriginIsAllowedTask(HttpRequestPtr pReq, Json::Value whitelist) const
{
    bool result{};


    for (auto host : whitelist)
    {
        if (host.asString().rfind(pReq->getHeader("origin"), 0) == 0)
        {
            result = true;
            break;
        }
    }


    co_return result;
}