/**
 * @file ResultTypes.h
 * @author Prana Ron (prthg@proton.me)
 * 
 * @brief type collection for result keyword/prefix
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
 */
#ifndef PRTHGCPP_RESULT_TYPES_H
#define PRTHGCPP_RESULT_TYPES_H
#include <string>
#include <vector>
#include <array>

#include "prthgcpp/inc/helpers/enums/UserEnums.h"


namespace prthgcpp
{


    /**
     * @brief type common result with message
     * 
     */
    typedef struct
    {
        bool m_result;
        std::string m_message;
    } TResultCommon;


    typedef struct
    {
        bool m_result;
        std::string m_message;
        std::string m_email;
        std::string m_username;
        std::string m_tokenWeb;
        std::string m_tokenIOT;
        std::string m_tokenMobile;
        std::string m_tokenDesktop;
        std::array<prthgcpp::EUserRole, 4> m_userRoles;
        std::array<prthgcpp::EUserRoleOrg, 4> m_userRolesOrg;
    } TResultSignIn;


} // namespace prthgcpp


#endif // PRTHGCPP_RESULT_TYPES_H