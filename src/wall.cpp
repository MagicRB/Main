#include "wall.h"

#include <functional>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

wall::wall()
{
    //ctor
}

int wall::render(databank* db)
{
    rect.x = db->getResX() / 2 + x * db->getCHX() - db->getCX() - db->getCHX() / 2;
    rect.y = db->getResY() / 2 + y * db->getCHY() - db->getCY() - db->getCHY() / 2;
    rect.w = db->getCHX();
    rect.h = db->getCHY();

    SDL_RenderCopy(db->getSDL_RENDERER(), texture, NULL, &rect);

    return 0;
}

int wall::init(databank* db)
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

void wall::setPos(float xx, float xy)
{
    x = xx;
    y = xy;
}

bool wall::getCollision(databank* db/*, player* pl*/)
{
    return true;
}

wall::position wall::getPos()
{
    position pos;
    pos.x = x;
    pos.y = y;
    return pos;
}

wall::~wall()
{
    //dtor
}
