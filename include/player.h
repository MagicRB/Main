#ifndef PLAYER_H
#define PLAYER_H

#include <databank.h>

class player
{
    public:
        player();

        int init(databank*);
        int render(databank*);

        ~player();
    protected:

        SDL_Texture* texture = NULL;
        SDL_Rect rect;

    private:
};

#endif // PLAYER_H



