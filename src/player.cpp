#include "player.h"

#include <iostream>

#include <databank.h>

player::player()
{
    //ctor
}

int player::init(databank* db)
{
    db->subscribeEvent([this](databank* db)
    {
        this->render(db);
    });

    texture = IMG_LoadTexture(db->getSDL_RENDERER(), "mods/Main/textures/stone_wall_horizontal.png");

    if (texture == NULL)
    {
        std::cout << "img error " << SDL_GetError();
        return -1;
    }
    return 0;
}

int player::render(databank* db)
{
    rect.x = db->getResX() / 2 - db->getCHX() / 2;
    rect.y = db->getResY() / 2 - db->getCHY() / 2;
    rect.w = db->getCHX();
    rect.h = db->getCHY();

    SDL_RenderCopy(db->getSDL_RENDERER(), texture, NULL, &rect);

    return 0;
}

player::~player()
{
    //dtor
}
