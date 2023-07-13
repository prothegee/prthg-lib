/**
 * @file ResultTypes.ts
 * @author Prana Ron (prthg@proton.me)
 * 
 * @brief internal types collection for Status keyword/prefix
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
*/
import type { EBackendConstMessage } from "../enums/BackendEnums";
import type { EUserRole, EUserRoleOrg } from "../enums/UserEnums";


/**
 * @brief type common result with message
*/
export type TResultCommon = {
    m_isOk:boolean;
    m_message:string;
}


/**
 * @brief type result when do sign-in
*/
export type TResultSignIn = {
    m_isOk:boolean;
    m_message:string;
    m_email:string;
    m_sessionTokenWeb:string;
    m_sessionTokenIOT:string;
    m_sessionTokenMobile:string;
    m_sessionTokenDesktop:string;
    m_userRoles:EUserRole[];
    m_userRolesOrg:EUserRoleOrg[];
    
}


export type TBackendConstMessage = {
    m_messageStatus:EBackendConstMessage;
    m_messageContext:string;
}