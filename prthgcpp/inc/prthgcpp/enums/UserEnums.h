/**
 * @file UserEnums.h
 * @author Prana Ron (prothegee@protonmail.com)
 * 
 * @brief enum (constant/class) for user keyword/prefix
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prothegee@protonmail.com)
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
        is_editor_of_content, // only allowed to edit internal content
        is_default, // common to sign-in requirement LAST
    };
    enum EUserRole : int
    {
        eUserRole_undefined = 0,
        eUserRole_sudo, // 1st authorithy, able to do anything mostly
        eUserRole_admin, // 2nd authorithy, able to do anything, except delete user with sudo role
        eUserRole_staff, // 3rd authorithy, able to do anything, except delete user
        eUserRole_editor_of_content, // only allowed to edit internal content
        eUserRole_default, // common to sign-in requirement LAST
    };

    
    // enum class of user role organization/vendor/tenant, meaning
    // part of an organization/vendor creation
    // if your main database has organization/vendor/multi tenant registration, assign user role with this
    enum class ECUserRoleOrg : int
    {
        undefined = 0,
        is_owner, // 1st authorithy, able to do anything mostly in their organization/vendor/tenant
        is_manager, // 2nd authorithy, able to do anything, except remove user role with owner role in their organization/vendor/tenant
        is_analytic, // 3rd authorithy, only able to do anylytic stuff in their organization/vendor/tenant
        is_editor_of_content, // 3rd authorithy, only able to edit content in their organization/vendor/tenant
        is_editor_of_item_stock, // 3rd authorithy, only able to edit item stock in their organization/vendor/tenant
        is_editor_of_item_product, // 3rd authorithy, only able to edit item product view in their organization/vendor/tenant
        is_editor_of_cashier_or_order, // 3rd authorithy, only able to edit cashier/product order in their organization/vendor/tenant
    };
    // enum of user role organization/vendor/tenant, meaning
    // part of an organization/vendor creation
    // if your main database has organization/vendor/multi tenant registration, assign user role with this
    enum EUserRoleOrg : int
    {
        eUserRoleOrg_undefined = 0,
        eUserRoleOrg_owner, // 1st authorithy, able to do anything mostly in their organization/vendor/tenant
        eUserRoleOrg_manager, // 2nd authorithy, able to do anything, except remove user role with owner role in their organization/vendor/tenant
        eUserRoleOrg_analytic, // 3rd authorithy, only able to do anylytic stuff in their organization/vendor/tenant
        eUserRoleOrg_editor_of_content, // 3rd authorithy, only able to edit content in their organization/vendor/tenant
        eUserRoleOrg_editor_of_item_stock, // 3rd authorithy, only able to edit item stock in their organization/vendor/tenant
        eUserRoleOrg_editor_of_item_product, // 3rd authorithy, only able to edit item product view in their organization/vendor/tenant
        eUserRoleOrg_editor_of_cashier_or_order, // 3rd authorithy, only able to edit cashier/product order in their organization/vendor/tenant
    };


} // namespace prthgcpp


#endif // PRTHGCPP_USER_ENUMS_H