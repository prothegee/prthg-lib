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








template <typename T>
bool prthgcpp::drogon::CHostAndUrl::EvaluateOriginIsAllowed(HttpRequestPtr pReq, T whitelist) const
{
    bool result{};


    if (std::is_same<T, Json::Value>::value)
    {
        for (auto host : whitelist)
        {
            if (host.asString().rfind(pReq->getHeader("origin"), 0) == 0)
            {
                result = true;
                break;
            }
        }
    }

    if (std::is_same<T, std::vector>::value)
    {
        for (const auto &host : whitelist)
        {
            if (host.rfind(pReq->getHeader("origin"), 0) == 0)
            {
                result = true;
                break;
            }
        }
    }


    return result;
}




template <typename T>
Task<bool> prthgcpp::drogon::CHostAndUrl::EvaluateOriginIsAllowedTask(HttpRequestPtr pReq, T whitelist) const
{
    bool result{};


    if (std::is_same<T, Json::Value>::value)
    {
        for (auto host : whitelist)
        {
            if (host.asString().rfind(pReq->getHeader("origin"), 0) == 0)
            {
                result = true;
                break;
            }
        }
    }

    if (std::is_same<T, std::vector>::value)
    {
        for (const auto &host : whitelist)
        {
            if (host.rfind(pReq->getHeader("origin"), 0) == 0)
            {
                result = true;
                break;
            }
        }
    }


    co_return result;
}