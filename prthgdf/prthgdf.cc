#include "prthgdf.h"


prthgdf::CPrthgDf::CPrthgDf()
{
    {
        if (gPtrPrthgDf->pBackend == nullptr)
            gPtrPrthgDf->pBackend = std::make_shared<SBackend>();
        {
            if (gPtrPrthgDf->pBackend->LanguageContext == nullptr)
                gPtrPrthgDf->pBackend->LanguageContext = std::make_shared<prthgdf::CLanguageContext>();
        }
    }
    {
        if (gPtrPrthgDf->pDrogonFramework == nullptr)
            gPtrPrthgDf->pDrogonFramework = std::make_shared<SDrogonFramework>();
        {
            if (gPtrPrthgDf->pDrogonFramework->HostAndUrl == nullptr)
                gPtrPrthgDf->pDrogonFramework->HostAndUrl = std::make_shared<prthgdf::CHostAndUrl>();
        }
    }
}

prthgdf::CPrthgDf::~CPrthgDf()
{
}








int prthgdf::CPrthgDf::Int420()
{
    return 420;
}
