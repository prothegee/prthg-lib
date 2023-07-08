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
#include <array>


namespace prthgcpp
{


    /**
     * @brief type struct common result with message
     * 
     */
    struct TResultCommon
    {
        bool m_isOk;
        std::string m_message;
    };


    /**
     * @brief type struct result when do sign-in
     * 
     * @tparam T1 either use ECUserRole or EUserRole for m_userRoles
     * @tparam T2 either use ECUserRoleOrg or EUserRoleOrg for m_userRolesOrg
     */
    template<typename T1, typename T2>
    struct TResultSignIn
    {
        bool m_isOk;
        std::string m_message;
        std::string m_email;
        std::string m_username;
        std::string m_tokenWeb;
        std::string m_tokenIOT;
        std::string m_tokenMobile;
        std::string m_tokenDesktop;
        std::array<T1, 4> m_userRoles;
        std::array<T2, 4> m_userRolesOrg;
    };


} // namespace prthgcpp

#endif // PRTHGCPP_RESULT_TYPES_H