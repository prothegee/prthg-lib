/**
 * @file prthgcpp.h
 * @author Prana Ron (prothegee@protonmail.com)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prothegee@protonmail.com)
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


#include "prthgcpp/config.gen.h"


#ifdef __PRTHGCPP_INC_CRYPTOPP__
    #include "prthgcpp/classes/Cryptography.h"
#endif


#include "prthgcpp/classes/DateAndTime.h"
#include "prthgcpp/classes/MailSystem.h"
#include "prthgcpp/classes/Utility.h"


#ifdef __PRTHGCPP_INC_DROGON__
    #include <drogon/drogon.h>

    #include "prthgcpp/classes/HostAndUrl.h"
    #include "prthgcpp/classes/ViewContent.h"
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


        #ifdef __PRTHGCPP_INC_CRYPTOPP__
        // cryptography shared pointer
        static inline std::shared_ptr<prthgcpp::CCryptography> pCryptography = std::make_shared<prthgcpp::CCryptography>();
        #endif

        // date and time shared pointer
        static inline std::shared_ptr<prthgcpp::CDateAndTime> pDateAndTime = std::make_shared<prthgcpp::CDateAndTime>();

        // mail system shared pointer
        static inline std::shared_ptr<prthgcpp::CMailSystem> pMailSystem = std::make_shared<prthgcpp::CMailSystem>();

        // utility shared pointer
        static inline std::shared_ptr<prthgcpp::CUtility> pUtility = std::make_shared<prthgcpp::CUtility>();


        #ifdef __PRTHGCPP_INC_DROGON__
        struct SDrogonFramework
        {
            // host and url shared pointer
            static inline std::shared_ptr<prthgcpp::CHostAndUrl> HostAndUrl = std::make_shared<prthgcpp::CHostAndUrl>();

            // view content shared pointer
            static inline std::shared_ptr<prthgcpp::CViewContent> ViewContent = std::make_shared<prthgcpp::CViewContent>();
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