#include "sign.h"

#include <functional>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

sign::sign()
{
    //ctor
}

int sign::render(databank* db)
{
    rect.x = db->getResX() / 2 + x * db->getCHX() - db->getCX() - db->getCHX() / 2;
    rect.y = db->getResY() / 2 + y * db->getCHY() - db->getCY() - db->getCHY() / 2;
    rect.w = db->getCHX();
    rect.h = db->getCHY();

    SDL_RenderCopy(db->getSDL_RENDERER(), texture, NULL, &rect);

    return 0;
}

int sign::init(databank* db)
{
    db->subscribeEvent([this](databank* db)
     {
     this->render(db);
    });

    texture = IMG_LoadTexture(db->getSDL_RENDERER(), "mods/Main/textures/sign.png");

    if (texture == NULL)
    {
        std::cout << "img error" << SDL_GetError();
        return -1;
    }
    return 0;
}

void sign::setPos(float xx, float xy)
{
    x = xx;
    y = xy;
}

bool sign::getCollision(databank* db/*, player* pl*/)
{
    return false;
}

sign::position sign::getPos()
{
    position pos;
    pos.x = x;
    pos.y = y;
    return pos;
}

sign::~sign()
{
    //dtor
}
