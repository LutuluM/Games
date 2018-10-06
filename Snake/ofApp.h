#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
	    int fps;
	    int points = 0;
	    int width = 500;//ofGetWindowWidth();
        int height = 500;//ofGetWindowHeight();
	    int foodx = 0;
        int foody = 0;
        int snakex = 100;
        int snakey = 100;
        int velsnakex = 25;
        int velsnakey = 0;
        int snakelength = 2;
        int snakelengthx[400];
        int snakelengthy[400];
        int gameover = 0;
        int exitgame;
        void foodspawn();
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
