/**
 * @file BackendEnums.ts
 * @author Prana Ron (prthg@proton.me)
 * 
 * @brief internal enums collection for user keyword/prefix
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
*/
export enum EUserRole
{
    undefined = 0,
    is_sudo, // 1st authorithy, able to do anything mostly
    is_admin, // 2nd authorithy, able to do anything, except delete user with sudo role
    is_staff, // 3rd authorithy, able to do anything, except delete user
    is_editor_of_content, // only allowed to edit internal content
    is_default, // common to sign-in requirement LAST
}


export enum EUserRoleOrg
{
    undefined = 0,
    is_owner, // 1st authorithy, able to do anything mostly in their organization/vendor/tenant
    is_manager, // 2nd authorithy, able to do anything, except remove user role with owner role in their organization/vendor/tenant
    is_analytic, // 3rd authorithy, only able to do anylytic stuff in their organization/vendor/tenant
    is_editor_of_content, // 3rd authorithy, only able to edit content in their organization/vendor/tenant
    is_editor_of_item_stock, // 3rd authorithy, only able to edit item stock in their organization/vendor/tenant
    is_editor_of_item_product, // 3rd authorithy, only able to edit item product view in their organization/vendor/tenant
    is_editor_of_cashier_or_order, // 3rd authorithy, only able to edit cashier/product order in their organization/vendor/tenant
}