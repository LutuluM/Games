#ifndef GOOMBA_H
#define GOOMBA_H
#include "Enemy.h"
class Goomba : public Enemy
{
    public:
        Goomba();

    protected:

    private:
        float x;
        float y;
        int direction;
};

#endif // GOOMBA_H
