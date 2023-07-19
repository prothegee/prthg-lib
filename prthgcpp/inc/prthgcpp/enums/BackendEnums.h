/**
 * @file BackendEnums.h
 * @author Prana Ron (prothegee@protonmail.com)
 * 
 * @brief enum (constant/class) for backend keyword/prefix
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prothegee@protonmail.com)
 * 
 */
#ifndef PRTHGCPP_BACKEND_ENUMS_H
#define PRTHGCPP_BACKEND_ENUMS_H


namespace prthgcpp
{


    enum class ECBackendConstMessage : int
    {
        reset_password_token_expired                    = -3,
        reset_password_error                            = -2,
        verify_email_token_expired                      = -1,
        undefined                                       = 0, // E.Q. nothing to show
        verify_email_token_verified                     = 1,
        reset_password_ok                               = 2,
        reset_password_token_verified                   = 3,
    };
    enum EBackendConstMessage : int
    {
        eMessageStatus_reset_password_token_expired     = -3,
        eMessageStatus_reset_password_error             = -2,
        eMessageStatus_verify_email_token_expired       = -1,
        eMessageStatus_undefined                        = 0, // E.Q. nothing to show
        eMessageStatus_verify_email_token_verified      = 1,
        eMessageStatus_reset_password_ok                = 2,
        eMessageStatus_reset_password_token_verified    = 3,
    };


} // namespace prthgcpp


#endif // PRTHGCPP_BACKEND_ENUMS_H