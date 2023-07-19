/**
 * @file BackendEnums.ts
 * @author Prana Ron (prothegee@protonmail.com)
 * 
 * @brief internal enums collection for Backend keyword/prefix
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prothegee@protonmail.com)
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