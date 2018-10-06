#include "Enemy.h"
#include "Camera.h"

Enemy::Enemy()
{
    //ctor
}

void Enemy::setup(int x_in, int y_in)
{
    x=x_in;
    y=y_in;
    direction=-1;
}

void Enemy::move()
{
    y+=.2;
    x+=direction*.05;

}
void Enemy::collide(Camera& cam)
{
    if(cam.tileType(x,y+.9)||cam.tileType(x+.98,y+.9)) y=(int)y;
    if(cam.tileType(x+cam.getOffset(),y) && direction<0)
    {
        direction=1;
        image.mirror(false,true);
    }
    else if (cam.tileType(x+.95+cam.getOffset(),y) && direction>0)
    {
        direction=-1;
        image.mirror(false,true);
    }
}
void Enemy::move2(float x_in)
{
    x-=x_in;
}
float Enemy::getx()
{
    return x;
}
float Enemy::gety()
{
    return y;
}
bool Enemy::kill()
{
    return(x<-.79||x>30||y<0||y>16);
}
void Enemy::draw()
{
    image.draw(x*scaleX,y*scaleY,scaleY,scaleY);
    //ctor
}
Enemy::~Enemy()
{
    //dtor
}
