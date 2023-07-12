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
    token_expired_for_email_verification = -1,

    undefined = 0, // E.Q. nothing to show

    token_verified_for_email_verification = 1,
}