/**
 * @file prthgcpp.h
 * @author Prana Ron (prthg@proton.me)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
*/
#ifndef PRTHGCPP_H
#define PRTHGCPP_H
#include <memory>
#include <drogon/drogon.h>

#include "prthgcpp/inc/drogon/HostAndUrl.h"


namespace prthgcpp
{
    class prthgcpp::drogon::CHostAndUrl;




    /**
     * @brief global prthgcpp structure
     * 
     */
    struct SGlobal final
    {
        SGlobal();
        ~SGlobal();


        struct SDrogonFramework
        {
            // host and url shared pointer
            static inline std::shared_ptr<prthgcpp::drogon::CHostAndUrl> HostAndUrl = std::make_shared<prthgcpp::drogon::CHostAndUrl>();
        };

        // optional pointer to prthgcpp drogon namespace
        static inline std::shared_ptr<SDrogonFramework> pDrogonFramework = std::make_shared<SDrogonFramework>();


        /**
         * @brief just say a hello from global struct
         * 
         */
        void SayHello();
    };




    /**
     * @brief prthgcpp global shared pointer access
     * 
     */
    static inline std::shared_ptr<SGlobal> gsPtr = std::make_shared<SGlobal>();
} // namespace prthgcpp


#endif // PRTHGCPP_H