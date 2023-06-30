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
}