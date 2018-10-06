#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include "Reset.h"

class PauseMenu
{
    public:
        PauseMenu();
        ofImage pause;
        void resume(int&);
        void mainMenu(int&);
        void menuUp();
        void menuDown();
        void draw();
        void initalize();
        int getLocal();
        virtual ~PauseMenu();

    protected:

    private:
        void setMenu();
        int menuLocal;
};

#endif // PAUSEMENU_H
