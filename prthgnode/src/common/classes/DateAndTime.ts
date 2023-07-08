/**
 * @file DateAndTime.ts
 * @author Prana Ron (prthg@proton.me)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
*/
import CEndUser from "./EndUser";
import { EDateAndTimeFormat } from "../enums/DateEnums";


/**
 * @brief date and time class
 * 
 * @note extend from CEndUser
*/
export default class CDateAndTime extends CEndUser
{
    constructor()
    {
        super();
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