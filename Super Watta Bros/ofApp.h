#pragma once

#include "ofMain.h"
#include "PauseMenu.h"
#include "Enemy.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

        int screen;

		StartScreen startScreen;
		World world;
		Camera camera;
		Player watta;
		Reset reset;
		PauseMenu pauseMenu;
		WorldSelect wSelect;
		int currentLevel;
		int life;
		vector<Enemy> enemy;

		void keyPressed(int key);
		void keyReleased(int key);
};
