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
#if _WIN32
    #ifndef NOMINMAX
    #define NOMINMAX
    #endif // NOMINMAX

    #undef min
    #undef max
#endif // _WIN32
#include <memory>
#include <drogon/drogon.h>

#include "prthgcpp/inc/Cryptography.h"
#include "prthgcpp/inc/Utility.h"

#include "prthgcpp/inc/drogon/HostAndUrl.h"


namespace prthgcpp
{




    /**
     * @brief global prthgcpp structure
     * 
     */
    struct SGlobal final
    {
        SGlobal();
        ~SGlobal();


        // cryptography shared pointer
        static inline std::shared_ptr<prthgcpp::CCryptography> pCryptography = std::make_shared<prthgcpp::CCryptography>();

        // utility shared pointer
        static inline std::shared_ptr<prthgcpp::CUtility> pUtility = std::make_shared<prthgcpp::CUtility>();


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