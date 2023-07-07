/**
 * @file DateAndTime.h
 * @author Prana Ron (prthg@proton.me)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
 */
#ifndef PRTHGCPP_DATE_AND_TIME_H
#define PRTHGCPP_DATE_AND_TIME_H
#include <time.h>
#include <chrono>
#include <string>

#include "prthgcpp/inc/helpers/enums/DateEnums.h"


namespace prthgcpp
{


    /**
     * @brief prthgcpp date and time class
     * 
     */
    class CDateAndTime
    {
    private:
        time_t m_rawtime = time(0);
        tm* m_timeinfo = localtime(&m_rawtime);


    protected:
        /* data */


    public:
        CDateAndTime(/* args */);
        ~CDateAndTime();


        const int m_year   = [&](){ return 1900 + m_timeinfo->tm_year; }();

        const int m_month  = [&](){ return m_timeinfo->tm_mon + 1; }();

        const int m_day    = [&](){ return m_timeinfo->tm_mday; }();

        const int m_hour   = [&](){ return m_timeinfo->tm_hour; }();

        const int m_minute = [&](){ return m_timeinfo->tm_min; }();

        const int m_second = [&](){ return m_timeinfo->tm_sec; }();


        std::string GetTime(const prthgcpp::ECDateAndTimeFormat dateAndTimeFormat) const;
    };


} // namespace prthgcpp


#endif // PRTHGCPP_DATE_AND_TIME_H