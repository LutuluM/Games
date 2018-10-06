#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include "ofImage.h"
#include "ofAppRunner.h"


class StartScreen
{
    public:
        StartScreen();
        ofImage screen;
        void draw();
        nextScreen(int &);

        virtual ~StartScreen();

    protected:

    private:
};

#endif // STARTSCREEN_H
