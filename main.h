#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include <databank.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

void DLL_EXPORT loadObjects(databank* db, std::vector<std::string> ObjV);
void DLL_EXPORT initMod(databank* db);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
