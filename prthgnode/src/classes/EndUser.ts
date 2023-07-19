/**
 * @file EndUser.ts
 * @author Prana Ron (prothegee@protonmail.com)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prothegee@protonmail.com)
 * 
*/
// import { EDateAndTimeFormat } from "../enums/DateEnums";


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

    readonly m_browserOS:string;

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
    /**
     * @brief minutes
    */
    readonly m_mm:number;
    /**
     * @brief seconds
    */
    readonly m_ss:number;


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

        let browserOS:string;
        const userAgent:string = this.m_userAgent;
        if (userAgent.indexOf("Android") > -1)
        {
            browserOS = "Android";
        }
        else if (userAgent.indexOf("iPhone") > -1)
        {
            browserOS = "iPhone";
        }
        else if (userAgent.indexOf("Linux") > -1)
        {
            browserOS = "Linux";
        }
        else if (userAgent.indexOf("Macintosh") > -1)
        {
            browserOS = "MacOS";
        }
        else if (userAgent.indexOf("Windows") > -1)
        {
            browserOS = "Windows";
        }
        else
        {
            browserOS = "undefined";
        }
        this.m_browserOS = browserOS;

        this.m_YYYY = new Date().getFullYear();
        this.m_MM = new Date().getMonth() + 1;
        this.m_DD = new Date().getDate();
        this.m_hh = new Date().getHours();
        this.m_mm = new Date().getMinutes();
        this.m_ss = new Date().getSeconds();
    }
}