#include "ofApp.h"
#include "functions.h"

//--------------------------------------------------------------
void ofApp::setup(){
ofSetFrameRate(60);
ofSetEscapeQuitsApp(false);
screen=1;
currentLevel=1;
life=1;
}

//--------------------------------------------------------------
void ofApp::update(){
switch(screen)
{
    case 1:
    case 3:
        break;
    case 2:
        switch(watta.update(camera,world,enemy))
        {
            case 1:currentLevel++;life++;if(currentLevel>2)setup();
            case 2:life--;reset.levelReset(watta,camera,world,screen,wSelect,currentLevel);if(life==0)setup();
            case 0:break;
        }

        camera.spawnEnemies(enemy,world);
        for (vector<Enemy>::iterator it = enemy.begin() ; it != enemy.end();)
        {
            it->move();
            it->collide(camera);
            if((it->getx() >= watta.x) && (it->getx() <= watta.x + watta.width) && (it->gety() <= watta.y + watta.height) && (it->gety() >= watta.y))
            {
                life--;
            }
            if(it->kill()) enemy.erase(it);
            else ++it;
        }
        if(life<0)
        {
            setup();
            for (vector<Enemy>::iterator it = enemy.begin() ; it != enemy.end();)enemy.erase(it);
        }
    default:break;
}
}
//--------------------------------------------------------------
void ofApp::draw(){
    if (screen>=5) fun();
switch(screen)
{
    case 1:
        startScreen.draw();
        life=3;
        break;
    case 2:
        camera.draw();
        watta.draw(camera);
        for (vector<Enemy>::iterator it = enemy.begin() ; it != enemy.end(); ++it)  it->draw();
        ofSetColor(0,0,0);
        ofDrawBitmapString(ofToString(ofGetFrameRate()),10,10);
        ofDrawBitmapString("LIVES:"+ofToString(life),10,20);
        ofSetColor(255,255,255);
        break;
    case 3:
        pauseMenu.draw();
    default:break;
}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
if(key=='f')ofToggleFullscreen();
switch(screen)
{
    case 1:
    if (key==' ')
        {
            reset.gameReset(watta,camera,world,screen,wSelect,currentLevel);
            startScreen.nextScreen(screen);
        }
    else if(key==OF_KEY_ESC) std::exit(0);
        break;
    case 2:
        if(key=='a')     watta.move(key,-.1);
        else if(key=='d')watta.move(key,.1);
        else if(key==' ')watta.jump();
        else if(key=='r')
        {
            for (vector<Enemy>::iterator it = enemy.begin() ; it != enemy.end();)enemy.erase(it);
            reset.levelReset(watta,camera,world,screen,wSelect,currentLevel);
        }
        else if(key=='1')
        {
            for (vector<Enemy>::iterator it = enemy.begin() ; it != enemy.end();)enemy.erase(it);
            currentLevel=1;
            reset.levelReset(watta,camera,world,screen,wSelect,currentLevel);
        }
        else if(key=='2')
        {
            for (vector<Enemy>::iterator it = enemy.begin() ; it != enemy.end();)enemy.erase(it);
            currentLevel=2;
            reset.levelReset(watta,camera,world,screen,wSelect,currentLevel);
        }
        else if(key==OF_KEY_ESC)screen=3;
        break;
    case 3:
        if(key=='w')pauseMenu.menuUp();
        else if(key=='s')pauseMenu.menuDown();
        else if(key==' ')
        {
            switch (pauseMenu.getLocal())
            {
            case 0:
                pauseMenu.resume(screen);
                break;
            case 1:
                reset.levelReset(watta,camera,world,screen,wSelect,currentLevel);
                for (vector<Enemy>::iterator it = enemy.begin() ; it != enemy.end();)enemy.erase(it);
                pauseMenu.initalize();
                break;
            case 2:
                pauseMenu.mainMenu(screen);
                for (vector<Enemy>::iterator it = enemy.begin() ; it != enemy.end();)enemy.erase(it);
                pauseMenu.initalize();
                break;
            }
        }
    default:break;
}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
switch(screen)
{
    case 1:
    case 3:
        break;
    case 2:
        if(key=='a')     watta.move(key,0);
        else if(key=='d')watta.move(key,0);
        break;
}
if(key=='p')screen+=5;
if(key=='o')screen-=5;
}
