#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
	    void enemy();
	    void bulletHit();
	    void centRespawn();
	    int enemyMove;
	    int enemyLeft;
	    int score;
	    ofImage ship;
	    ofImage bullet;
	    struct bullets{int exist;int x;int y;};
        struct enemies{int active;int x;int y;int direction;int directionY;ofImage alien;};
        struct player{int lives;int x;int y;int velx;int velx1;int vely;int vely1;bullets bullet[20];};
        struct Shrooms{int active;float x;float y;int state;ofImage shroom;};
        Shrooms shrooms[25][30];
        enemies foes[20];
        player user;

		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);

};
