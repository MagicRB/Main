#include "mainControls.h"

mainControls::mainControls()
{
    //ctor
}

bool mainControls::checkColl(databank* db, float dx, float dy)
{
    databank::position pos;
    pos.x = db->plx + dx;
    pos.y = db->ply + dy;

    for (unsigned int i = 0; i < db->blp_v.size(); i++)
    {
        std::cout << db->blp_v.at(i).x << std::endl << db->blp_v.at(i).y << std::endl;
        std::cout << pos.x << std::endl << pos.y << std::endl;
        if (db->blp_v.at(i).x - dx == pos.x && db->blp_v.at(i).y - dy == pos.y)
        {
            return db->bl_v.at(i)->getCollision(db);
        }
    }
    return false;
}

void mainControls::eventHandle(databank* db)
{
    SDL_Event* e = db->getSDL_EVENT();
    if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_w)
    {
        if (checkColl(db, 0, -0.5) == false)
        {
            db->ply = db->ply - 0.25;
            db->setCY(db->ply * db->getCHY());
        }
    }
    else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_a)
    {
        if (checkColl(db, -0.5, 0) == false)
        {
            db->plx = db->plx - 0.25;
            db->setCX(db->plx * db->getCHX());
        }
    }
    else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_s)
    {
        if (checkColl(db, 0, 0.5) == false)
        {
            db->ply = db->ply + 0.25;
            db->setCY(db->ply * db->getCHY());
        }
    }
    else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_d)
    {
        if (checkColl(db, 0.5, 0) == false)
        {
            db->plx = db->plx + 0.25;
            db->setCX(db->plx * db->getCHX());
        }
    }
    else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_q)
    {
        db->safeQuit();
    }
}

int mainControls::init(databank* db)
{
    db->subscribeEEvent([this](databank* db)
    {
    this->eventHandle(db);
    });

    return 0;
}

mainControls::~mainControls()
{
    //dtor
}
