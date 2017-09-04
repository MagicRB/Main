#ifndef SIGN_H
#define SIGN_H

#include <block.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include <databank.h>

class sign : public block
{
    public:
        sign();
        ~sign();

        virtual int render(databank* db);
        virtual int init(databank* db);
        virtual void setPos(float x, float y);
        virtual bool getCollision(databank* db/*, player* pl*/);
        virtual position getPos();
    protected:



    private:
};

#endif // SIGN_H
