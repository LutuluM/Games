#include "ofApp.h"
#include <time.h>

int foodPositionx()
{
    int position = 25*(rand()%20);
    return (position);
}
int foodPositiony()
{
    int position = 25*(rand()%20);
    return (position);
}
void ofApp::foodspawn()
{
    foodx = foodPositionx();
    foody = foodPositiony();
}
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(6);
    srand(time(0));
    foodspawn();
    snakelengthx[0] = snakex;
    snakelengthy[0] = snakey;
}

//--------------------------------------------------------------
void ofApp::update(){
    fps = ofGetFrameRate();
    snakex += velsnakex;
    snakey += velsnakey;
    if (snakex > width - 25 || snakex < 0 || snakey > height - 25 || snakey < 0) gameover = 1;
    if (snakelengthx[0] == foodx && snakelengthy[0] == foody)
        {
            foodspawn();
            points +=1;
            snakelength +=1;
        }
    int i;
    for (i = 1; i < snakelength ; ++i)
        {
            if(snakelengthx[0]==snakelengthx[i] && snakelengthy[0]==snakelengthy[i]) gameover = 1;
        }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,0,0);
    ofRect(0,0,width,height);
    int i;
    for (i = snakelength; i > 0; --i)
        {
            snakelengthx[i] = snakelengthx[i-1];
        }
    for (i = snakelength; i > 0; --i)
        {
            snakelengthy[i] = snakelengthy[i-1];
        }
    snakelengthx[0]=snakex;
    snakelengthy[0]=snakey;
    for (i = 1; i < snakelength; ++i)
        {
            ofSetColor(0,255,0);
            ofRect(snakelengthx[i],snakelengthy[i],25,25);
        }
    ofSetColor(255,123,0);
    ofRect(foodx,foody, 25, 25);
    ofSetColor(255,0,0);
    ofRect(snakelengthx[0], snakelengthy[0], 25, 25);
    ofSetColor(255,255,255);
    ofDrawBitmapString("fps: " + ofToString(fps) , 2, 10);
    ofDrawBitmapString("points: " + ofToString(points) , 2, 40);
    if (gameover == 1)
        {
            ofSetColor(255,0,0);
            ofDrawBitmapString("GAMEOVER!!! " , 240, 240);
            if(exitgame == 1)
            {
                Sleep(2500);
                std::exit(0);
            }

            exitgame = 1;
        }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'w' || key == 357)
        {
            velsnakex = 0;
            velsnakey = -25;
        }
    else if (key == 'a' || key == 356)
        {
            velsnakex = -25;
            velsnakey = 0;
        }
    else if (key == 's' || key == 359)
        {
            velsnakex = 0;
            velsnakey = 25;
        }
    else if (key == 'd' || key == 358)
        {
            velsnakex = 25;
            velsnakey = 0;
        }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
