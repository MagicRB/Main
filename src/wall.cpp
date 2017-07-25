#include "wall.h"

#include <windows.h>
#include <functional>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

wall::wall()
{
    //ctor
}

int block::render(databank* db)
{
    rect.x = ((block::x - db->getCX()) * db->getCHX()) - db->getCHX() / 2;
    rect.y = ((block::y - db->getCY()) * db->getCHY()) - db->getCHY() / 2;
    rect.w = db->getCHX();
    rect.h = db->getCHY();

    SDL_RenderCopy(db->getSDL_RENDERER(), texture, NULL, &rect);

    return 0;
}

int block::init(databank* db)
{
    db->subscribeEvent([this](databank* db)
    {
    this->render(db);
    });

    texture = IMG_LoadTexture(db->getSDL_RENDERER(), ("mods/Main/textures/stone_wall_" + tPath + ".png").c_str());

    if (texture == NULL)
    {
        std::cout << "img error " << SDL_GetError();
        return -1;
    }
    return 0;
}

void block::setRot(rotations rot1x, rotations rot2x)
{
    rot1 = rot1x;
    rot2 = rot2x;
}

void block::setPos(int x, int y)
{
    block::x = x;
    block::y = y;
}

bool block::getCollision(databank* db/*, player* pl*/)
{
    return true;
}

block::position block::getPos()
{
    position pos;
    pos.x = block::x;
    pos.y = block::y;
    return pos;
}

wall::~wall()
{
    //dtor
}
