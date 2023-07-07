#include "prthgcpp/inc/drogon/MailSystem.h"


prthgcpp::drogon::CMailSystem::CMailSystem()
{
}

prthgcpp::drogon::CMailSystem::~CMailSystem()
{
}








prthgcpp::TResultMessage prthgcpp::drogon::CMailSystem::SMailioTLS::SendTextMessage(const std::string senderName, const std::string senderEmail, const std::string recipientName, const std::string recipientEmail, const std::string mailSubject, const std::string mailContent, const std::string mailServer, const std::string mailAuthUser, const std::string mailAuthPassword) const
{
    TResultMessage result;


    /*
    example usage function:

    prthgcpp::drogon::CMailSystem::SMailioTLS mailsys;
    auto result = mailsys.SendTextMessage(
        "sendername", "sender@domain.tld",
        "recipient", "recipient@domain.tld",
        "[subject] - foo of bar", "It's a foo bar\n\n---\n\nbaz baz!",
        "smtp-relay.domain.tld",
        "mailauth@domain.tld", "mailauthpassword"
    );
    */
    // 


    try
    {
        mailio::message msg;

        msg.header_codec(mailio::message::header_codec_t::BASE64);
        msg.from(mailio::mail_address(senderName, senderEmail));
        msg.add_recipient(mailio::mail_address(recipientName, recipientEmail));

        msg.subject(mailSubject);
        msg.content_transfer_encoding(mailio::mime::content_transfer_encoding_t::QUOTED_PRINTABLE);
        msg.content_type(mailio::message::media_type_t::TEXT, "plain", "utf-8");

        msg.content(mailContent);

        mailio::smtps conn(mailServer, 587);

        conn.authenticate(mailAuthUser, mailAuthPassword, mailio::smtps::auth_method_t::START_TLS);

        conn.submit(msg);

        result.m_result = true;
        result.m_message = "Email has been sent";
    }
    catch(mailio::smtp_error &e)
    {
        result.m_result = false;
        result.m_message = e.what();

        std::cout << "(ERR) - " << result.m_message << "\n";
    }
    catch(mailio::dialog_error &e)
    {
        result.m_result = false;
        result.m_message = e.what();

        std::cout << "(ERR) - " << result.m_message << "\n";
    }
    


    return result;
}




Task<prthgcpp::TResultMessage> prthgcpp::drogon::CMailSystem::SMailioTLS::SendTextMessageTask(const std::string senderName, const std::string senderEmail, const std::string recipientName, const std::string recipientEmail, const std::string mailSubject, const std::string mailContent, const std::string mailServer, const std::string mailAuthUser, const std::string mailAuthPassword) const
{
    TResultMessage result;


    /*
    example usage function:

    prthgcpp::drogon::CMailSystem::SMailioTLS mailsys;
    auto result = co_await mailsys.SendTextMessageTask(
        "sendername", "sender@domain.tld",
        "recipient", "recipient@domain.tld",
        "[subject] - foo of bar", "It's a foo bar\n\n---\n\nbaz baz!",
        "smtp-relay.domain.tld",
        "mailauth@domain.tld", "mailauthpassword"
    );
    */
    // 


    try
    {
        mailio::message msg;

        msg.header_codec(mailio::message::header_codec_t::BASE64);
        msg.from(mailio::mail_address(senderName, senderEmail));
        msg.add_recipient(mailio::mail_address(recipientName, recipientEmail));

        msg.subject(mailSubject);
        msg.content_transfer_encoding(mailio::mime::content_transfer_encoding_t::QUOTED_PRINTABLE);
        msg.content_type(mailio::message::media_type_t::TEXT, "plain", "utf-8");

        msg.content(mailContent);

        mailio::smtps conn(mailServer, 587);

        conn.authenticate(mailAuthUser, mailAuthPassword, mailio::smtps::auth_method_t::START_TLS);

        conn.submit(msg);

        result.m_result = true;
        result.m_message = "Email has been sent";
    }
    catch(mailio::smtp_error &e)
    {
        result.m_result = false;
        result.m_message = e.what();

        std::cout << "(ERR) - " << result.m_message << "\n";
    }
    catch(mailio::dialog_error &e)
    {
        result.m_result = false;
        result.m_message = e.what();

        std::cout << "(ERR) - " << result.m_message << "\n";
    }


    co_return result;
}