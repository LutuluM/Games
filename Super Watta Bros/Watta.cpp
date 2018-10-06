#include "Watta.h"

Watta::Watta()
{
    image.loadImage("1");
    time=ofGetElapsedTimeMillis();
    time0=ofGetElapsedTimeMillis();
    x=100;
    y=ofGetWindowHeight()/2;
    vely=0;
    accel=50;
    scale=100;
    image.resize(scale,scale);
    //ctor
}
void Watta::draw()
{
    ofPushMatrix();
    ofTranslate(x,y);
    ofRotate(vely*3);
    image.draw(-image.width/2,-image.height/2);
    ofPopMatrix();
}
void Watta::move()
{
    time=ofGetElapsedTimeMillis();
    vely+=accel*(time-time0)/400;
    y+=vely*(time-time0)/20;
    time0=time;
    if(y>ofGetWindowHeight()-scale/2)   y=ofGetWindowHeight()-scale/2;
    if(y<scale/2)   y=scale/2;
}


void Watta::jump()
{
    vely=-20;
    accel=50;
}
void Watta::update()
{
    move();
}
Watta::~Watta()
{
    //dtor
}
