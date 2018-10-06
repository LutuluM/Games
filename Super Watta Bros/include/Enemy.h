#ifndef ENEMY_H
#define ENEMY_H
#include "ofImage.h"
#include "ofapprunner.h"
#include "ofGraphics.h"
#include "vector"
#define scaleX ofGetWindowWidth()/24
#define scaleY ofGetWindowHeight()/16
class Camera;
class Enemy
{
    public:
        Enemy();
        virtual void setup(int x_in, int y_in);
        virtual void move();
        virtual void draw();
        virtual void move2(float x);
        virtual bool kill();
        virtual void collide(Camera&);
        virtual ~Enemy();
        ofImage image;
        virtual float getx();
        virtual float gety();
    protected:

    private:
        int direction;
        float x,y;
};

#include "Goomba.h"
#include "Koopa.h"
#endif // ENEMY_H
