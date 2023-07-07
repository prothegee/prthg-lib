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

import { EDateAndTimeFormat } from "../enums/DateEnums";

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


    /**
     * @brief get current time
     * 
     * @note with at least 2 character
     * 
     * @param dateAndTimeFormat
     * 
     * @returns string
    */
    public GetTime(dateAndTimeFormat:EDateAndTimeFormat):string
    {
        let result:string;


        switch (dateAndTimeFormat)
        {
            case EDateAndTimeFormat.FULL_TIMESTAMP:
            {
                const year = this.m_YYYY;
                const yearStr = year.toString();

                const month = this.m_MM;
                const monthStr = (month < 10) ? `0${month.toString()}` : month.toString();

                const day = this.m_DD;
                const dayStr = (day < 10) ? `0${day.toString()}` : day.toString();

                const hour = this.m_hh;
                const hourStr = (hour < 10) ? `0${hour.toString()}` : hour.toString();

                const minute = this.m_mm;
                const minuteStr = (minute < 10) ? `0${minute.toString()}` : minute.toString();

                const second = this.m_ss;
                const secondStr = (second < 10) ? `0${second.toString()}` : second.toString();


                result = `${yearStr}${monthStr}${dayStr}${hourStr}${minuteStr}${secondStr}`;
            }
            break;




            case EDateAndTimeFormat.YYYYMMDD:
            {
                const year = this.m_YYYY;
                const yearStr = year.toString();

                const month = this.m_MM;
                const monthStr = (month < 10) ? `0${month.toString()}` : month.toString();

                const day = this.m_DD;
                const dayStr = (day < 10) ? `0${day.toString()}` : day.toString();


                result = `${yearStr}${monthStr}${dayStr}`;
            }
            break;




            case EDateAndTimeFormat.MM:
            {
                result = (this.m_MM < 10) ? `0${this.m_MM.toString()}` : this.m_MM.toString();
            }
            break;




            case EDateAndTimeFormat.DD:
            {
                result = (this.m_DD < 10) ? `0${this.m_DD.toString()}` : this.m_DD.toString();
            }
            break;




            case EDateAndTimeFormat.hhmmss:
            {
                const hour = this.m_hh;
                const hourStr = (hour < 10) ? `0${hour.toString()}` : hour.toString();

                const minute = this.m_mm;
                const minuteStr = (minute < 10) ? `0${minute.toString()}` : minute.toString();

                const second = this.m_ss;
                const secondStr = (second < 10) ? `0${second.toString()}` : second.toString();


                result = `${hourStr}:${minuteStr}:${secondStr}`;
            }
            break;




            case EDateAndTimeFormat.hh:
            {
                result = (this.m_hh < 10) ? `0${this.m_hh.toString()}` : this.m_hh.toString();
            }
            break;




            case EDateAndTimeFormat.mm:
            {
                result = (this.m_mm < 10) ? `0${this.m_mm.toString()}` : this.m_mm.toString();
            }
            break;




            case EDateAndTimeFormat.ss:
            {
                result = (this.m_ss < 10) ? `0${this.m_ss.toString()}` : this.m_ss.toString();
            }
            break;




            default:
            {
                result = "ERR";
            }
            break;
        }


        return result;
    }
}