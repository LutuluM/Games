#include "Reset.h"

Reset::Reset()
{
    //ctor
}
void Reset::levelReset(Player& player,Camera& cam,World& world,int & screen,WorldSelect& wSelect,int level)
{
    world.initalize(wSelect.select(level));
    player.setup();
    cam.setup(world);
    screen=2;
}
void Reset::gameReset(Player& player ,Camera& cam,World& world,int & screen,WorldSelect& wSelect,int level)
{
    world.initalize(wSelect.select(level));
    player.setup();
    cam.setup(world);
    screen=1;

}
Reset::~Reset()
{
    //dtor
}
