#include "prthgcpp/inc/drogon/HostAndUrl.h"


prthgcpp::CHostAndUrl::CHostAndUrl()
{
}

prthgcpp::CHostAndUrl::~CHostAndUrl()
{
}








bool prthgcpp::CHostAndUrl::CheckOriginToAllowAccess(HttpRequestPtr pReq, Json::Value whitelistDomain)
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


Task<bool> prthgcpp::CHostAndUrl::CheckOriginToAllowAccessTask(HttpRequestPtr pReq, Json::Value whitelistDomain)
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








void prthgcpp::CHostAndUrl::EvaluateHostIsAllowed(HttpRequestPtr pReq, const std::string allowedHost, HttpResponsePtr pResp, std::function<void(const HttpResponsePtr &)> callback)
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

void prthgcpp::CHostAndUrl::EvaluateHostsIsAllowed(HttpRequestPtr pReq, const std::vector<std::string> allowedHosts, HttpResponsePtr pResp, std::function<void(const HttpResponsePtr &)> callback)
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








Task<void> prthgcpp::CHostAndUrl::EvaluateHostIsAllowedTask(HttpRequestPtr pReq, const std::string allowedHost, HttpResponsePtr pResp, std::function<void(const HttpResponsePtr &)> callback)
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

Task<void> prthgcpp::CHostAndUrl::EvaluateHostsIsAllowedTask(HttpRequestPtr pReq, const const std::vector<std::string> allowedHosts, HttpResponsePtr pResp, std::function<void(const HttpResponsePtr &)> callback)
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








bool prthgcpp::CHostAndUrl::EvaluateOriginIsAllowed(HttpRequestPtr pReq, Json::Value whitelist) const
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




Task<bool> prthgcpp::CHostAndUrl::EvaluateOriginIsAllowedTask(HttpRequestPtr pReq, Json::Value whitelist) const
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