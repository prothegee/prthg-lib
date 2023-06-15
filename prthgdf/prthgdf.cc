#include "prthgdf.h"


prthgdf::CPrthgDf::CPrthgDf()
{
}

prthgdf::CPrthgDf::~CPrthgDf()
{
}








int prthgdf::CPrthgDf::Int420()
{
    return 420;
}




int prthgdf::CPrthgDf::Status()
{
    return app().getCustomConfig()["Status"].asInt();
}








bool prthgdf::CPrthgDf::IsStaging()
{
    return (app().getCustomConfig()["Status"].asInt() == 2) ? true : false;
}








std::string prthgdf::CPrthgDf::EnvDomain()
{
    return app().getCustomConfig()["EnvDomain"].asString();
}


std::string prthgdf::CPrthgDf::EnvProject()
{
    return app().getCustomConfig()["EnvProject"].asString();
}


std::string prthgdf::CPrthgDf::EnvVersion()
{
    return app().getCustomConfig()["EnvVersion"].asString();
}
