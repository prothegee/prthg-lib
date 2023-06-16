/**
 * @file ViewContext.h
 * @author Prana Ron (prothegee@protonmail.com)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prothegee@protonmail.com)
 * 
 */
#ifndef PRTHGDF_VIEW_CONTEXT_H
#define PRTHGDF_VIEW_CONTEXT_H
#include <drogon/drogon.h>


using namespace drogon;


namespace prthgdf
{


    /**
     * @brief view context class handler, related to HttpViewData
     * 
     */
    class CViewContext final
    {
    private:
        /* data */


    protected:
        /* data */


    public:
        CViewContext(/* args */);
        ~CViewContext();


        // shared public view data property
        HttpViewData SharedViewData;


        void InvokeCutomConfig(HttpRequestPtr pReq);
    };


} // namespace prthgdf


#endif // PRTHGDF_VIEW_CONTEXT_H