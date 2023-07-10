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
#ifndef PRTHGCPP_MAIL_SYSTEM_H
#define PRTHGCPP_MAIL_SYSTEM_H
#include "prthgcpp/config.h"
#include "prthgcpp/inc/helpers/types/ResultTypes.h"


#ifdef __PRTHGLIB_INC_DROGON__
    #include <drogon/drogon.h>

    using namespace drogon;
#endif // __PRTHGLIB_INC_DROGON__


#ifdef __PRTHGLIB_INC_MAILIO__
    #include <mailio/message.hpp>
    #include <mailio/mime.hpp>
    #include <mailio/smtp.hpp>
#endif // __PRTHGLIB_INC_MAILIO__


namespace prthgcpp
{


    class CMailSystem
    {
    private:
        /* data */


    protected:
        /* data */


    public:
        CMailSystem(/* args */);
        ~CMailSystem();


        #ifdef __PRTHGLIB_INC_MAILIO__
        // mail system struct using mailio tls method
        struct SMailioTLS
        {
            prthgcpp::TResultCommon SendTextMessage(const std::string senderName, const std::string senderEmail, const std::string recipientName, const std::string recipientEmail, const std::string mailSubject, const std::string mailContent, const std::string mailServer, const std::string mailAuthUser, const std::string mailAuthPassword) const;


            #ifdef __PRTHGLIB_INC_DROGON__
            Task<prthgcpp::TResultCommon> SendTextMessageTask(const std::string senderName, const std::string senderEmail, const std::string recipientName, const std::string recipientEmail, const std::string mailSubject, const std::string mailContent, const std::string mailServer, const std::string mailAuthUser, const std::string mailAuthPassword) const;
            #endif // __PRTHGLIB_INC_DROGON__
        };
        #endif // __PRTHGLIB_INC_MAILIO__
    };


} // namespace prthgcpp


#endif // PRTHGCPP_MAIL_SYSTEM_H