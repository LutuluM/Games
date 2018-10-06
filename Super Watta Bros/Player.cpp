#include "Player.h"

Player::Player()
{
    setup();
}

void Player::setup()
{
    width=0.91;
    height=.95;
    x=2;
    y=13;
    vely=20;
    accel=45;
    lVel=0;
    rVel=0;
    player.loadImage("1");
}

void Player::draw(Camera& cam)
{
    ofSetColor(255,255,255);
    player.draw(x*scaleX,y*scaleY,scaleX,scaleY);
}

int Player::update(Camera& cam, World& world, vector<Enemy>& enemy)
{
    dt=(float)1/60;
    vely+=accel*dt;
    y+=vely*dt;
    x+=rVel+lVel;
    if(x<0)x=0;
    else if(x>cam.getWidth()-10*width)
        {
        if(!cam.move(.2,0,world))
        {
            x=cam.getWidth()-10*width;
            for (vector<Enemy>::iterator it = enemy.begin() ; it != enemy.end();)
            {
                it->move2(.2);
                it->collide(cam);
                if(it->kill()) enemy.erase(it);
                else ++it;
            }
        }
        else if(x>cam.getWidth()-1) x=cam.getWidth()-1;
        }
    collision(cam,world);
    if(y<0)
        {
            y=0;
            vely=0;
        }
    if(y>cam.getHeight()-height)return 2;
    if(x>20) return 1;
    return 0;
}

void Player::jump()
{
if(grounded)
    {
        vely=-20;
    }
}

void Player::collision(Camera& cam, World& world)
{
    int i,x1,y1,x2;

    bool temp1 = cam.tileType(x+cam.getOffset(),y);
    bool temp2 = cam.tileType(x+width+cam.getOffset(),y);
    bool temp3 = cam.tileType(x+width+cam.getOffset(),y+height);
    bool temp4 = cam.tileType(x+cam.getOffset(),y+height);
    bool temp5 = false;
    if(temp1 || (temp1 && temp2))
    {
        x1=x+cam.getOffset();
        y1=y;
        x2=x+cam.getOffset()+cam.x;
        if(cam.tiles[x1][y1]==8)
        {
            world.tiles[x2][y1]=0;
            cam.tiles[x1][y1]=0;
        }
    }
    else if(temp2);
    {
    x1=x+cam.getOffset()+1;
    y1=y;
    x2=x+cam.getOffset()+cam.x+1;
    if(cam.tiles[x1][y1]==8)
        {
            world.tiles[x2][y1]=0;
            cam.tiles[x1][y1]=0;
        }
    }
    grounded=false;
    if(temp4 || temp3)
    {
        grounded=true;
    }
    if (temp2 && temp3)
    {
        x=(int)(x+1)-cam.getOffset();
        temp5=true;
        temp1 = cam.tileType(x+cam.getOffset(),y);
        temp4 = cam.tileType(x+cam.getOffset(),y+height);
    }
    if (temp1 && temp4)
    {
        x=(int)(x+1)+cam.getOffset();
        temp5=true;
        temp1 = cam.tileType(x+cam.getOffset(),y);
        temp2 = cam.tileType(x+width+cam.getOffset(),y);
    }
    if (temp1 && temp2)
        {
            vely=0;
            temp5=true;
            temp3 = cam.tileType(x+width+cam.getOffset(),y+height);
            temp4 = cam.tileType(x+cam.getOffset(),y+height);
        }
    if (temp3 && temp4)
        {
            vely-=accel*dt;
            y=(int)y;
            temp5=true;
        }

    if(!temp5)
    {
        if (temp1 && vely<0)
            {
                vely=0;
                y=(int)(y+1);
            }
        else if (temp1 && vely>0) x=(int)(x+1);
        else if (temp2 && vely<0)
            {
                vely=0;
                y=(int)(y+1);
            }
        else if (temp2 && vely>0) x=(int)(x);
        else if (temp3 && vely<0) x=(int)(x);
        else if (temp3 && vely>0)
            {
                vely-=accel*dt;
                y=(int)y;
            }
        else if (temp4 && vely<0) x=(int)(x+1);
        else if (temp4 && vely>0)

            {
                vely-=accel*dt;
                y=(int)y;
            }
    }
}

void Player::move(char a, float val)
{
    switch (a)
    {
        case 'a':lVel=val;
                 break;
        case 'd':rVel=val;
                 break;
    }
}

Player::~Player()
{
    //dtor
}
