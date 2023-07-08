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


    // enum class for date and time format
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
    // enum for date and time format
    enum EDateAndTimeFormat : int
    {
        eDateAndTime_format_undefined = 0,
        eDateAndTime_format_UTC_TIME,
        eDateAndTime_format_FULL_TIMESTAMP,
        eDateAndTime_format_YYYYMMDD,
        eDateAndTime_format_YYYY,
        eDateAndTime_format_MM,
        eDateAndTime_format_DD,
        eDateAndTime_format_hhmmss,
        eDateAndTime_format_hh,
        eDateAndTime_format_mm,
        eDateAndTime_format_ss,
    };
} // namespace prthgcpp


#endif // PRTHGCPP_DATE_ENUMS_H