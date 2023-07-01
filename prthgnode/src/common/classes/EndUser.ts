/**
 * @file EndUser.ts
 * @author Prana Ron (prthg@proton.me)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
*/
/**
 * @brief end user class
*/
export default class CEndUser
{
    private m_ready:boolean;
    
    /**
     * @brief timezone
    */
    readonly m_tz:string;
    /**
     * @brief timezone name
    */
    readonly m_tzn:string|undefined;

    readonly m_userAgent:string;

    readonly m_dateTime:string;

    /**
     * @brief year
    */
    readonly m_YYYY:number;
    /**
     * @brief month
    */
    readonly m_MM:number;
    /**
     * @brief day
    */
    readonly m_DD:number;
    /**
     * @brief hours
    */
    readonly m_hh:number;


    constructor()
    {
        this.m_ready = true;

        this.m_tz = Intl.DateTimeFormat().resolvedOptions().timeZone;
        this.m_tzn = Intl.DateTimeFormat().resolvedOptions().timeZoneName;

        this.m_userAgent = navigator.userAgent;

        const currentDate = new Date();
        const cDate = currentDate.getFullYear() + '-' + (currentDate.getMonth() + 1) + '-' + currentDate.getDate();
        const cTime = currentDate.getHours() + ":" + currentDate.getMinutes() + ":" + currentDate.getSeconds();
        const dateTime = cDate + ' ' + cTime + ` ( ${this.m_tz} )`;
        this.m_dateTime = dateTime;

        this.m_YYYY = new Date().getFullYear();
        this.m_MM = new Date().getMonth() + 1;
        this.m_DD = new Date().getDate();
        this.m_hh = new Date().getHours();
    }
}