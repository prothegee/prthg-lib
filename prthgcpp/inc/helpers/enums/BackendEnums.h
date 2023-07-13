/**
 * @file BackendEnums.h
 * @author Prana Ron (prthg@proton.me)
 * 
 * @brief enum (constant/class) for backend keyword/prefix
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
 */
#ifndef PRTHGCPP_BACKEND_ENUMS_H
#define PRTHGCPP_BACKEND_ENUMS_H


namespace prthgcpp
{


    enum class ECBackendConstMessage : int
    {
        token_expired_for_email_verification = -1,
        undefined = 0, // E.Q. nothing to show
        token_verified_for_email_verification = 1,
    };
    enum ECBakendConstMessage : int
    {
        eMessageStatus_token_expired_for_email_verification = -1,
        eMessageStatus_undefined = 0, // E.Q. nothing to show
        eMessageStatus_token_verified_for_email_verification = 1,
    };


} // namespace prthgcpp


#endif // PRTHGCPP_BACKEND_ENUMS_H