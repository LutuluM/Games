#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
	    void enemy();
	    void bulletHit();
	    int enemyDirection = 1;
	    int shipColor;
	    ofImage alien;
	    ofImage ship;
	    ofImage bullet;
	    int totalBullets=20;
	    struct bullets{int exist;int x;int y;};
        struct enemies{int active;float x;float y;bullets bullet;};
        struct player{int lives;int x;int y;int velx;int velx1;int vely;int vely1;bullets bullet[20];};
        enemies foes[3][10];
        player user;

		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);

};
