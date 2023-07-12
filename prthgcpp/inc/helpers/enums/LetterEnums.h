/**
 * @file LetterEnums.h
 * @author Prana Ron (prthg@proton.me)
 * 
 * @brief enum (constant/class) for letter keyword/prefix
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
 */
#ifndef PRTHGCPP_LETTER_ENUMS_H
#define PRTHGCPP_LETTER_ENUMS_H


namespace prthgcpp
{


    // enum class of letter case
    enum class ECLetterCase : int
    {
        undefined = 0,
        lowercase,
        uppercase,
        mixedcase,
    };
    // enum of letter case
    enum ELetterCase : int
    {
        eLetterCase_undefined = 0,
        eLetterCase_lowercase,
        eLetterCase_uppercase,
        eLetterCase_mixedcase,
    };


} // namespace prthgcpp


#endif // PRTHGCPP_LETTER_ENUMS_H