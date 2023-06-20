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
import { SupportedLanguage } from "../constants/SupportConst";
import { EStorageLocal } from "../enums/EStorage";


/**
 * @brief internal enduser class accesss
 * 
 * @note commonly for current user interaction
*/
export default class CEndUser
{
    public SetDefaultLanguage():void
    {
        let isSupported = false;
        let defaultLang = "";

        const currentLanguage:string = navigator.language;


        for (const lang of SupportedLanguage)
        {
            if (currentLanguage.includes(lang))
            {
                isSupported = true;
                defaultLang = lang;
                break;
            }
        }

        if (!isSupported) defaultLang = "en";


        this.SetLocalStorageOf(EStorageLocal._default_language, defaultLang);
    }




    //#region localStorage
    /**
     * @brief get locaStorage from predefined enum first param
     * 
     * @param localStorageName
     * 
     * @returns string | null
    */
    public GetLocalStorageOf(localStorageName:EStorageLocal):string|null
    {
        let result: string|null;

    
        switch (localStorageName)
        {
            case EStorageLocal._default_language:
                result = localStorage.getItem("_default_language");
            break;
        }


        return result;
    }


    /**
     * @brief set localStorage from predefined enum first param
     * 
     * @param localStorageName
     * @param language
    */
    // eslint-disable-next-line @typescript-eslint/no-explicit-any
    public SetLocalStorageOf(localStorageName:EStorageLocal, language:any):void
    {
        switch (localStorageName)
        {
            case EStorageLocal._default_language:
                localStorage.setItem("_default_language", language);        
            break;
        }
    }
    //#endregion
}