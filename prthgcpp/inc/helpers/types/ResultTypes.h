/**
 * @file ResultTypes.h
 * @author Prana Ron (prthg@proton.me)
 * 
 * @brief type collection for result keyword/prefix
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
 */
#ifndef PRTHGCPP_RESULT_TYPES_H
#define PRTHGCPP_RESULT_TYPES_H
#include <string>
#include <vector>


namespace prthgcpp
{


    /**
     * @brief type common result with message
     * 
     */
    typedef struct
    {
        bool m_result;
        std::string m_message;
    } TResultMessage;


} // namespace prthgcpp


#endif // PRTHGCPP_RESULT_TYPES_H