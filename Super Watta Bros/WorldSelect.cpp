#include "WorldSelect.h"

WorldSelect::WorldSelect()
{
    //ctor
}
char * WorldSelect::select(int level)
{
    switch (level)
    {
    case 1:return "world1.txt";
    case 2:return "world1.1.txt";
    }
}

WorldSelect::~WorldSelect()
{
    //dtor
}
