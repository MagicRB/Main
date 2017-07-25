#ifndef MAINCONTROLS_H
#define MAINCONTROLS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include <databank.h>

class mainControls
{
    public:
        mainControls();
        ~mainControls();

        bool checkColl(databank* db, int dx, int dy);

        void eventHandle(databank* db);

        int init(databank* db);

    protected:

    private:
};

#endif // MAINCONTROLS_H
