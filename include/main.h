#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef _WIN32
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

#else

#include <databank.h>


extern "C"
{

extern void loadObjects(databank* db, std::vector<std::string> ObjV);
extern void initMod(databank* db);

}


#endif // _WIN32

#endif // __MAIN_H__

