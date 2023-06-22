/**
 * @file RouteControl.ts
 * @author Prana Ron (prthg@proton.me)
 * 
 * @copyright Copyright (c) 2023
 * 
 * @contributors:
 * - Prana Ron @prothegee (prthg@proton.me)
 * 
*/

import { SupportedLanguage } from "../constants/SupportConst";

/**
 * @brief rout control class
*/
export default class CRouteControl
{
    private m_ready:boolean;


    constructor()
    {
        this.m_ready = true;
    }




    /**
     * @brief redirect page/path to param
     * 
     * @param urlOrPath
    */
    public RedirectTo(urlOrPath:string):void
    {
        if (urlOrPath.length >= 1)
        {
            window.location.href = urlOrPath;
        }
    }




    /**
     * @brief redirect if param 1 language is not supported
     * 
     * @param languageData - a language data pass from lang param route
     * @param subPath - e.g. "/home" or "/about" & etc. must start with slash
     * @param force - force redirec to 2nd param
    */
    public RedirectIfLanguageNotSupported(languageData:string, subPath:string, force:boolean):void
    {
        let ok = false;

        let userLang:string = languageData;

        for (const lang of SupportedLanguage)
        {
            if (userLang.includes(lang))
            {
                ok = true;
                break;
            }
        }

        if (!ok)
        {
            userLang = "en";

            if (subPath.length <= 0)
            {
                window.location.href = `/${userLang}`;
            }
            else if (subPath.length >= 1)
            {
                window.location.href = `/${userLang}${subPath}`;
            }
        }

        if (force)
        {
            window.location.href = `/${userLang}${subPath}`;
        }
    }
}