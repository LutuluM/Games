#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
	    int fps;
        int minemap[420];
        void MineSetup();
        void MinePick(int mx, int my);
        void MineFlag(int mx, int my);
        int MineNumber(int position);
        int gameover = 0;
        int winning = 0;
        void MinesLeft();
        int time1 = time(NULL);
        int time2 = 0;

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
