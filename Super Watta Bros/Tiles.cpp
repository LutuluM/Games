#include "Tiles.h"

Tiles::Tiles()
{
    //ctor
}
void Tiles::setup(string image, int Type)
{
    icon.loadImage(image);
    type=Type;
    if(Type>0)collision=true;
    else collision=false;
}
Tiles::~Tiles()
{
    //dtor
}
