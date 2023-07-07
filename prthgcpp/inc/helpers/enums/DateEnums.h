/**
 * @file DateEnums.h
 * @author Prana Ron (prthg@proton.me)
 * 
 * @brief enum (constant/class) for date keyword/prefix
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
 */
#ifndef PRTHGCPP_DATE_ENUMS_H
#define PRTHGCPP_DATE_ENUMS_H


namespace prthgcpp
{


    /**
     * enum class for date and time format
     * ----------------------------
        SERVER_TIME = 0,
        UTC_TIME,
        FULL_TIMESTAMP,
        YYYYMMDD,
        YYYY,
        MM,
        DD,
        hhmmss,
        hh,
        mm,
        ss,
    * 
    */
    enum class ECDateAndTimeFormat : int
    {
        undefined = 0,
        UTC_TIME,
        FULL_TIMESTAMP,
        YYYYMMDD,
        YYYY,
        MM,
        DD,
        hhmmss,
        hh,
        mm,
        ss,
    };
} // namespace prthgcpp


#endif // PRTHGCPP_DATE_ENUMS_H