#ifndef WATTA_H
#define WATTA_H
#include "ofImage.h"
#include "ofGraphics.h"
#include "ofapprunner.h"

class Watta
{
    public:
        Watta();
        void draw();
        void update();
        void jump();
        ofImage image;
        virtual ~Watta();

    protected:

    private:
        void move();
        float time;
        float time0;
        float rotation;
        float x;
        float y;
        float vely;
        float accel;
        float scale;
};

#endif // WATTA_H
