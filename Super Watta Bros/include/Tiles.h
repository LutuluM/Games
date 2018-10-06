#ifndef TILES_H
#define TILES_H
#include "ofImage.h"

class Tiles
{
    public:
        Tiles();
        ofImage icon;
        void setup(string,int);
        int type;
        bool collision;
        virtual ~Tiles();

    protected:

    private:
};

#endif // TILES_H
