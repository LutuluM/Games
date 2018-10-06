#include "Camera.h"

Camera::Camera()
{
    width=24;
    height=16;

    int i,n=sizeof(tile)/sizeof(Tiles);
    char temp[20];
    for(i=0;i<n;i++)
    {
        sprintf(temp,"tiles/%d.png",i);
        tile[i].setup(temp,i);
    }
}
void Camera::setup(World& world)
{
    x=0;
    y=0;
    move(x,y,world);
}
void Camera::spawnEnemies(vector<Enemy>& enemy,World& world)
{
    int i,k,j;
    for(i=0;i<width+4;i++) for(k=0;k<height+4;k++)
    {
        j=world.tiles[i+(int)x][k+(int)y];
        if (j==10)
        {
            Goomba e;
            e.setup(i,k);
            enemy.push_back(e);
            world.tiles[i+(int)x][k+(int)y]=0;
            tiles[i][k]=0;
        }
        else if(j==11)
        {
            Koopa e;
            e.setup(i,k);
            enemy.push_back(e);
            world.tiles[i+(int)x][k+(int)y]=0;
            tiles[i][k]=0;
        }
    }
}
bool Camera::tileType(int x_in, int y_in)
{
    int i=tiles[x_in][y_in];
    return tile[i].collision;
}
int Camera::getWidth() {return width;}
int Camera::getHeight() {return height;}

bool Camera::move(float x_in, float y_in, World& world)
{
    bool edge=false;
    x+=x_in;
    y+=y_in;
    if(x<0)
    {
        x=0;
        edge=true;
    }
    if(y<0)
    {
        y=0;
        edge=true;
    }
    if(x>world.width-width-7)
    {
        x=world.width-width-7;
        edge=true;
    }
    if(y>world.height-height)
    {
        y=world.height-height;
        edge=true;
    }
    int i,k;
    for(i=0;i<width+7;i++) for(k=0;k<height;k++) tiles[i][k]=world.tiles[(int)x+i][(int)y+k];
    return edge;
}

void Camera::draw()
{
    int i,k,j;
    xOffset=x-(int)x;
    ofSetColor(255,255,255);
    for(i=0;i<width+7;i++) for(k=0;k<height;k++)
    {
        j=tiles[i][k];
        tile[j].icon.draw((i-xOffset)*scaleX,k*scaleY,scaleX+1,scaleY+1);
    }
}
float Camera::getOffset()
{
    return xOffset;
}
Camera::~Camera()
{
    //dtor
}
