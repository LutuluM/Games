#ifndef PLAYER_H
#define PLAYER_H
#include "Camera.h"
#include "ofMath.h"

class Player
{
    public:
        Player();
        ofImage player;
        void setup();
        void draw(Camera&);
        int update(Camera&,World&,vector<Enemy>&);
        void jump();
        void move(char,float);
        virtual ~Player();
        float x,y,height,width;
    protected:

    private:
        void collision(Camera&, World&);
        bool grounded;
        int lifes;

        float lVel, rVel;
        float dt;
        float time;
        float time0;
        float vely;
        float accel;
};

#endif // PLAYER_H
