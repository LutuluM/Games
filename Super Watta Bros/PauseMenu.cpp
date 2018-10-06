#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
    initalize();
    setMenu();
}
void PauseMenu::initalize()
{
    menuLocal=0;
    setMenu();
}
void PauseMenu::draw()
{
    pause.draw(0,0,ofGetWindowWidth(),ofGetWindowHeight());
}
void PauseMenu::resume(int & screen)
{
    screen=2;
}
void PauseMenu::mainMenu(int & screen)
{
    screen=1;
}
void PauseMenu::setMenu()
{
    switch (menuLocal)
    {
    case 0:
        pause.loadImage("pause1.png");
        break;
    case 1:
        pause.loadImage("pause2.png");
        break;
    case 2:
        pause.loadImage("pause3.png");
        break;
    }
}
void PauseMenu::menuUp()
{
    menuLocal=(menuLocal+2)%3;
    setMenu();
}
void PauseMenu::menuDown()
{
    menuLocal=(menuLocal+1)%3;
    setMenu();
}
int PauseMenu::getLocal()
{
    return menuLocal;
}
PauseMenu::~PauseMenu()
{
    //dtor
}
