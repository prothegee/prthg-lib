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


#include "prthgcpp/config.h"


#ifdef __PRTHGLIB_INC_CRYPTOPP__
    #include "prthgcpp/inc/Cryptography.h"
#endif


#include "prthgcpp/inc/Utility.h"


#ifdef __PRTHGLIB_INC_DROGON__
    #include <drogon/drogon.h>

    #include "prthgcpp/inc/drogon/HostAndUrl.h"
#endif


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


        #ifdef __PRTHGLIB_INC_CRYPTOPP__
        // cryptography shared pointer
        static inline std::shared_ptr<prthgcpp::CCryptography> pCryptography = std::make_shared<prthgcpp::CCryptography>();
        #endif

        // utility shared pointer
        static inline std::shared_ptr<prthgcpp::CUtility> pUtility = std::make_shared<prthgcpp::CUtility>();


        #ifdef __PRTHGLIB_INC_DROGON__
        struct SDrogonFramework
        {
            // host and url shared pointer
            static inline std::shared_ptr<prthgcpp::drogonframework::CHostAndUrl> HostAndUrl = std::make_shared<prthgcpp::drogonframework::CHostAndUrl>();
        };

        // optional pointer to prthgcpp drogon namespace
        static inline std::shared_ptr<SDrogonFramework> pDrogonFramework = std::make_shared<SDrogonFramework>();
        #endif


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