#include "prthgdf/ViewContext.h"


prthgdf::CViewContext::CViewContext(/* args */)
{
}

prthgdf::CViewContext::~CViewContext()
{
}








void prthgdf::CViewContext::InvokeCutomConfig(HttpRequestPtr pReq)
{
    SharedViewData.insert("status", std::to_string(app().getCustomConfig()["Status"].asInt()));

    SharedViewData.insert("domain", app().getCustomConfig()["EnvDomain"].asString());

    SharedViewData.insert("project", app().getCustomConfig()["EnvProject"].asString());

    SharedViewData.insert("version", app().getCustomConfig()["EnvVersion"].asString());
}
