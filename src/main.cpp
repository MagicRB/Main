#include "main.h"

#include <SDL2/SDL.h>

#include <databank.h>
#include <wall.h>
#include <mainControls.h>
#include <player.h> 
#include <sign.h>

#include <functional>
#include <vector>
#include <iostream>
#include <string>

#ifdef _WIN32
void DLL_EXPORT loadObjects(databank* db, std::vector<std::string> ObjV)
#else
void loadObjects(databank* db, std::vector<std::string> ObjV)
#endif // _WIN32
{
    if (db->vstr(ObjV, 1) == "wall")
    {
        wall* wl = new wall();

        db->bl_v.push_back(wl);

        wl->setPos(atoi(db->vstr(ObjV, 2).c_str()), atoi(db->vstr(ObjV, 3).c_str()));

        databank::position pos;
        pos.x = wl->getPos().x;
        pos.y = wl->getPos().y;
        db->blp_v.push_back(pos);

        wl->tPath = db->vstr(ObjV, 4);

        wl->init(db);
    } else if (db->vstr(ObjV, 1) == "player")
    {
        db->plx = std::stof(db->vstr(ObjV, 2));
        db->ply = std::stof(db->vstr(ObjV, 3));

        db->setCX(db->plx * db->getCHX());
        db->setCY(db->ply * db->getCHY());
    } else if (db->vstr(ObjV, 1) == "sign")
    {    
        sign* sg = new sign();

        sg->setPos(atoi(db->vstr(ObjV, 2).c_str()), atoi(db->vstr(ObjV, 3).c_str()));

        sg->init(db);
    }
}

#ifdef _WIN32
void DLL_EXPORT initMod(databank* db)
#else
void initMod(databank* db)
#endif // _WIN32
{
    db->subscribeLEvent([](databank* db, std::vector<std::string> ObjV)
    {
    loadObjects(db, ObjV);
    });

    if (db->getControls() == "Main")
    {
        mainControls* cntr = new mainControls();
        cntr->init(db);
    }

    if (db->getPlayerMod() == "Main")
    {
       player* plc = new player();
       plc->init(db);
    }
}

#ifdef _WIN32
extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
#endif
