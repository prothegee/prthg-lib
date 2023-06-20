/**
 * file prthgcpp.h
 * author Prana Ron (prthg@proton.me)
 * 
 * copyright Copyright (c) 2023
 * 
 * contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
*/
#ifndef PRTHGCPP_H
#define PRTHGCPP_H
#include <memory>


namespace prthgcpp
{


    /**
     * @brief global prthgcpp structure
     * 
     */
    struct SGlobal
    {
        SGlobal();
        ~SGlobal();


        #pragma region tool classes
        #pragma endregion


        /**
         * @brief just say a hello from global struct
         * 
         */
        void SayHello();
    };


    /**
     * @brief prthgcpp global shared pointer access
     * 
     */
    static inline std::shared_ptr<SGlobal> gsPtr = std::make_shared<SGlobal>();
} // namespace prthgcpp


#endif // PRTHGCPP_H