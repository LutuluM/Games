#ifndef CAMERA_H
#define CAMERA_H
#include "World.h"
#include "Tiles.h"
#include "stdio.h"
#include "Enemy.h"


class Camera
{
    public:
        Camera();
        bool move(float x_in, float y_in, World&);
        void draw();
        void setup(World&);
        int getWidth();
        int getHeight();
        float getOffset();
        bool tileType(int x_in, int y_in);
        void spawnEnemies(vector<Enemy>&,World&);
        float x;
        float y;
        int tiles[36][18];
        virtual ~Camera();

    protected:

    private:
        Tiles tile[12];
        int width;
        int height;
        float xOffset;
};

#endif // CAMERA_H
