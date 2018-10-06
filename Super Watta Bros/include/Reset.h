#ifndef RESET_H
#define RESET_H
#include "Player.h"
#include "StartScreen.h"
#include "WorldSelect.h"

class Reset
{
    public:
        Reset();
        void levelReset(Player&,Camera&,World&,int &,WorldSelect&,int);
        void gameReset(Player&,Camera&,World&,int &,WorldSelect&,int);
        virtual ~Reset();

    protected:

    private:
};

#endif // RESET_H
