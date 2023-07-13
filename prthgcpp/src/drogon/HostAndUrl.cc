#include "prthgcpp/inc/drogon/HostAndUrl.h"


prthgcpp::drogonframework::CHostAndUrl::CHostAndUrl()
{
}

prthgcpp::drogonframework::CHostAndUrl::~CHostAndUrl()
{
}








bool prthgcpp::drogonframework::CHostAndUrl::CheckOriginToAllowAccess(HttpRequestPtr pReq, Json::Value whitelistDomain)
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


Task<bool> prthgcpp::drogonframework::CHostAndUrl::CheckOriginToAllowAccessTask(HttpRequestPtr pReq, Json::Value whitelistDomain)
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








void prthgcpp::drogonframework::CHostAndUrl::EvaluateHostIsAllowed(HttpRequestPtr pReq, const std::string allowedHost, HttpResponsePtr pResp, std::function<void(const HttpResponsePtr &)> callback)
{
    bool allowed{};


    if (allowedHost.rfind(pReq->getHeader("host"), 0) == 0)
    {
        allowed = true;
    }

    if (!allowed)
    {
        pResp = HttpResponse::newHttpResponse();
        pResp->setStatusCode(k406NotAcceptable);

        callback(pResp);
    }
}

void prthgcpp::drogonframework::CHostAndUrl::EvaluateHostsIsAllowed(HttpRequestPtr pReq, const std::vector<std::string> allowedHosts, HttpResponsePtr pResp, std::function<void(const HttpResponsePtr &)> callback)
{
    bool allowed{false};

    for (auto host : allowedHosts)
    {
        if (pReq->getHeader("host") == host)
        {
            allowed = true;
            break;
        }
    }

    if (!allowed)
    {
        pResp = HttpResponse::newHttpResponse();
        pResp->setStatusCode(k406NotAcceptable);

        callback(pResp);
    }
}








Task<void> prthgcpp::drogonframework::CHostAndUrl::EvaluateHostIsAllowedTask(HttpRequestPtr pReq, const std::string allowedHost, HttpResponsePtr pResp, std::function<void(const HttpResponsePtr &)> callback)
{
    bool allowed{};


    if (allowedHost.rfind(pReq->getHeader("host"), 0) == 0)
    {
        allowed = true;
    }

    if (!allowed)
    {
        pResp = HttpResponse::newHttpResponse();
        pResp->setStatusCode(k406NotAcceptable);

        callback(pResp);
    }

    co_return; // seems not right?
}

Task<void> prthgcpp::drogonframework::CHostAndUrl::EvaluateHostsIsAllowedTask(HttpRequestPtr pReq, const const std::vector<std::string> allowedHosts, HttpResponsePtr pResp, std::function<void(const HttpResponsePtr &)> callback)
{
    bool allowed{false};

    for (auto host : allowedHosts)
    {
        if (pReq->getHeader("host") == host)
        {
            allowed = true;
            break;
        }
    }

    if (!allowed)
    {
        pResp = HttpResponse::newHttpResponse();
        pResp->setStatusCode(k406NotAcceptable);

        callback(pResp);
    }

    co_return; // seems not right?
}








bool prthgcpp::drogonframework::CHostAndUrl::EvaluateOriginIsAllowed(HttpRequestPtr pReq, Json::Value whitelist) const
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




Task<bool> prthgcpp::drogonframework::CHostAndUrl::EvaluateOriginIsAllowedTask(HttpRequestPtr pReq, Json::Value whitelist) const
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