#include "main.h"

#include <SDL2/SDL.h>

#include <databank.h>
#include <wall.h>
#include <mainControls.h>
#include <player.h>

#include <functional>
#include <vector>
#include <iostream>
#include <string>

void DLL_EXPORT loadObjects(databank* db, std::vector<std::string> ObjV)
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
        db->plx = atoi(db->vstr(ObjV, 2).c_str());
        db->ply = atoi(db->vstr(ObjV, 3).c_str());

        db->setCX((-1)*(db->getResX() / db->getCHX() / 2) + db->plx);
        db->setCY((-1)*(db->getResY() / db->getCHY() / 2) + db->ply);
    }
}

// a sample exported function
void DLL_EXPORT initMod(databank* db)
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
//        player* plc = new player();
//        plc->init(db);
    }

}

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
