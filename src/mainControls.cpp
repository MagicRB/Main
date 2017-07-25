#include "mainControls.h"

mainControls::mainControls()
{
    //ctor
}

bool mainControls::checkColl(databank* db, int dx, int dy)
{
    databank::position pos;
    pos.x = db->plx + dx;
    pos.y = db->ply + dy;

    for (unsigned int i = 0; i < db->blp_v.size(); i++)
    {
        if (db->blp_v.at(i).x == pos.x && db->blp_v.at(i).y == pos.y)
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
        if (checkColl(db, 0, -1) == false)
        {
            db->setCY(db->getCY() - 1);
            db->ply = db->ply - 1;
        }
    }
    else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_a)
    {
        if (checkColl(db, -1, 0) == false)
        {
            db->setCX(db->getCX() - 1);
            db->plx = db->plx - 1;
        }
    }
    else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_s)
    {
        if (checkColl(db, 0, 1) == false)
        {
            db->setCY(db->getCY() + 1);
            db->ply = db->ply + 1;
        }
    }
    else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_d)
    {
        if (checkColl(db, 1, 0) == false)
        {
            db->setCX(db->getCX() + 1);
            db->plx = db->plx + 1;
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
