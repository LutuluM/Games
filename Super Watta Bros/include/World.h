#ifndef WORLD_H
#define WORLD_H
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

class World
{
    public:
        World();
        initalize(char level[]);
        int width;
        int height;
        int **tiles;
        virtual ~World();

    protected:

    private:
};

#endif // WORLD_H
