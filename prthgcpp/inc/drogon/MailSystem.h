/**
 * @file MailSystem.h
 * @author Prana Ron (prthg@proton.me)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
 */
#ifndef PRTHHGCPP_MAIL_SYSTEM_H
#define PRTHHGCPP_MAIL_SYSTEM_H
#include <drogon/drogon.h>

#include <mailio/message.hpp>
#include <mailio/mime.hpp>
#include <mailio/smtp.hpp>

#include "prthgcpp/inc/helpers/types/ResultTypes.h"

#if _WIN32
    #ifndef _WIN32_WINNT
    #define _WIN32_WINNT 0x0A00
    #endif

    #ifndef _WIN32_WINDOWS
    #define _WIN32_WINDOWS 0x0A00
    #endif
#endif



using namespace drogon;


namespace prthgcpp::drogon
{


    /**
     * @brief prthgcpp mail system class
     * 
     */
    class CMailSystem
    {
    private:
        /* data */
        char at = '@';


    protected:
        /* data */


    public:
        CMailSystem(/* args */);
        ~CMailSystem();


        // mail system with mailio tls method
        struct SMailioTLS
        {
            /**
             * @brief send email text using mailio tls method
             * 
             * @note for example check MailSystem.cc line 27 - 34
             * 
             * @param senderName 
             * @param senderEmail 
             * @param recipientName 
             * @param recipientEmail 
             * @param mailSubject 
             * @param mailContent 
             * @param mailServer 
             * @param mailAuthUser 
             * @param mailAuthPassword 
             * @return prthgcpp::TResultCommon 
             */
            prthgcpp::TResultCommon SendTextMessage(const std::string senderName, const std::string senderEmail, const std::string recipientName, const std::string recipientEmail, const std::string mailSubject, const std::string mailContent, const std::string mailServer, const std::string mailAuthUser, const std::string mailAuthPassword) const;

            /**
             * @brief send email text using mailio tls method
             * 
             * @note coroutine
             * @note for example check MailSystem.cc line 93 - 100
             * 
             * @param senderName 
             * @param senderEmail 
             * @param recipientName 
             * @param recipientEmail 
             * @param mailSubject 
             * @param mailContent 
             * @param mailServer 
             * @param mailAuthUser 
             * @param mailAuthPassword 
             * @return Task<prthgcpp::TResultCommon> 
             */
            Task<prthgcpp::TResultCommon> SendTextMessageTask(const std::string senderName, const std::string senderEmail, const std::string recipientName, const std::string recipientEmail, const std::string mailSubject, const std::string mailContent, const std::string mailServer, const std::string mailAuthUser, const std::string mailAuthPassword) const;
        };
    };


} // namespace prthgcpp::drogon


#endif // PRTHHGCPP_MAIL_SYSTEM_H