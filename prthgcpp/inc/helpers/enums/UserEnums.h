/**
 * @file UserEnums.h
 * @author Prana Ron (prthg@proton.me)
 * 
 * @brief enum (constant/class) for user keyword/prefix
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
 * 
 */
#ifndef PRTHGCPP_USER_ENUMS_H
#define PRTHGCPP_USER_ENUMS_H


namespace prthgcpp
{


    // enum class of user role, meaning
    // not part of an organization/vendor creation
    // if your main database has organization/vendor/multi tenant registration, do not assign user role with this
    enum class ECUserRole : int
    {
        undefined = 0,
        is_sudo, // 1st authorithy, able to do anything mostly
        is_admin, // 2nd authorithy, able to do anything, except delete user with sudo role
        is_staff, // 3rd authorithy, able to do anything, except delete user
        is_default, // common to sign-in requirement
    };
    enum EUserRole : int
    {
        eUserRole_undefined = 0,
        eUserRole_sudo, // 1st authorithy, able to do anything mostly
        eUserRole_admin, // 2nd authorithy, able to do anything, except delete user with sudo role
        eUserRole_staff, // 3rd authorithy, able to do anything, except delete user
        eUserRole_default, // common to sign-in requirement
    };

    
    // enum class of user role organization/vendor/tenant, meaning
    // part of an organization/vendor creation
    // if your main database has organization/vendor/multi tenant registration, assign user role with this
    enum class ECUserRoleOrg : int
    {
        undefined = 0,
        is_owner, // 1st authorithy, able to do anything mostly in their organization/vendor/tenant
        is_administrative, // 2nd authorithy, able to do anything, except delete user with owner role in their organization/vendor/tenant
        is_editor_of_content, // 3rd authorithy, only able to edit content in their organization/vendor/tenant
        is_editor_of_cashier, // 4th authorithy, only able to edit cashier in their organization/vendor/tenant
    };
    // enum of user role organization/vendor/tenant, meaning
    // part of an organization/vendor creation
    // if your main database has organization/vendor/multi tenant registration, assign user role with this
    enum EUserRoleOrg : int
    {
        eUserRoleOrg_undefined = 0,
        eUserRoleOrg_isOwner, // 1st authorithy, able to do anything mostly in their organization/vendor/tenant
        eUserRoleOrg_isAdministrative, // 2nd authorithy, able to do anything, except delete user with owner role in their organization/vendor/tenant
        eUserRoleOrg_isEditorOfContent, // 3rd authorithy, only able to edit content in their organization/vendor/tenant
        eUserRoleOrg_isEditorOfCashier, // 4th authorithy, only able to edit cashier in their organization/vendor/tenant
    };


} // namespace prthgcpp


#endif // PRTHGCPP_USER_ENUMS_H