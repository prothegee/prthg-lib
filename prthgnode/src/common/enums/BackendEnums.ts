/**
 * @file BackendEnums.ts
 * @author Prana Ron (prthg@proton.me)
 * 
 * @brief internal enums collection for Backend keyword/prefix
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
*/
/**
 * @brief explicit project enum for backend const header
*/
export enum EBackendConstMessage
{
    reset_password_token_expired        = -3,
    reset_password_error                = -2,
    verify_email_token_expired          = -1,
    undefined                           = 0, // E.Q. nothing to show
    verify_email_token_verified         = 1,
    reset_password_ok                   = 2,
    reset_password_token_verified       = 3,
}