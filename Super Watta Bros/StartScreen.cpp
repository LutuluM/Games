#include "StartScreen.h"

StartScreen::StartScreen()
{
    screen.loadImage("background.png");
}
void StartScreen::draw()
{
    screen.draw(0,0,ofGetWindowWidth(),ofGetWindowHeight());
}
StartScreen::nextScreen(int & screen)
{
    screen=2;
}
StartScreen::~StartScreen()
{
    //dtor
}
