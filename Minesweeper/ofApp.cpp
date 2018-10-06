#include "ofApp.h"
#include <time.h>

/*
0 = A blank Covered Space
1 = A mine that is Covered
2 = An Uncovered Mine
3 = A Blank Space Uncovered
4 = A Flag
*/

void ofApp::MineSetup()
{
    int i = 0;
    int mines = 40;
    while (i < mines)
        {
            int x = 1 + rand()%400;
            if (minemap[x] == 0)
                {
                    minemap[x] = 1;
                    i += 1;
                }
        }
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::MinePick(int mx, int my)
{
    int position = ((my/25) % 20);
    position = position*20 + (1 + ((mx/25) % 20));
    if (minemap[position] == 1) minemap[position] = 2;
    else if (minemap[position] == 0) minemap[position] = 3;
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::MineFlag(int mx, int my)
{
    int position = ((my/25) % 20);
    position = position*20 + (1 + ((mx/25) % 20));
    if (minemap[position] > 9) minemap[position] -=10;
    else if (minemap[position] < 9 && minemap[position]!= 3) minemap[position] +=10;
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
int ofApp::MineNumber(int position)
{
    int minecount = 0;
    if (minemap[position-20] == 1 || minemap[position-20] == 11|| minemap[position-20] == 2) minecount += 1;
    if (minemap[position+20] == 1 || minemap[position+20] == 11|| minemap[position+20] == 2) minecount += 1;
    if (position%20 != 1)
        {
            if (minemap[position-1 ] == 1 || minemap[position-1] == 11 || minemap[position-1] == 2) minecount += 1;
            if (minemap[position+19] == 1 || minemap[position+19] == 11|| minemap[position+19] == 2) minecount += 1;
            if (minemap[position-21] == 1 || minemap[position-21] == 11|| minemap[position-21] == 2) minecount += 1;
        }
    if (position%20 != 0)
        {
            if (minemap[position-19] == 1 || minemap[position-19] == 11|| minemap[position-19] == 2) minecount += 1;
            if (minemap[position+1 ] == 1 || minemap[position+1] == 11 || minemap[position+1] == 2) minecount += 1;
            if (minemap[position+21] == 1 || minemap[position+21] == 11|| minemap[position+21] == 2) minecount += 1;
        }
    return(minecount);
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::MinesLeft()
{
    int unfoundMines = 0;
    int i;
    for (i=0; i < 400; ++i)
        {
            if (minemap[i+1] == 1) unfoundMines += 1;
            if (minemap[i+1] == 10 || minemap[i+1] == 0) unfoundMines += 1;
        }
    if (unfoundMines == 0) winning = 1;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//--------------------------------------------------------------
void ofApp::setup(){
    srand(time(NULL));
    ofBackground(255,255,255);
    MineSetup();
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    //fps = ofGetFrameRate();
    if (gameover == 1)
    {
        Sleep(2500);
        std::exit(0);
    }
    if (winning == 1)
    {
        Sleep(5000);
        std::exit(0);
    }
      MinesLeft();
}

//--------------------------------------------------------------
void ofApp::draw(){
    int i;
    for (i=0; i < 400; ++i)
        {
           /* if (minemap[i+1] == 1)//Covered space Mine and no Mine
                {
                    ofSetColor(200,0,255);
                    ofRect((i % 20)*25,(i/20)*25,23,23);
                }
            */if (minemap[i+1] == 0 || minemap[i+1] == 1)//Covered space Mine and no Mine
                {
                    ofSetColor(200,255,123);
                    ofRect((i % 20)*25,(i/20)*25,23,23);
                }

            else if (minemap[i+1] == 2)//Exposed Mines
                {
                    ofSetColor(255,0,0);
                    ofRect((i % 20)*25,(i/20)*25,23,23);
                    gameover = 1;
                }
            else if (minemap[i+1] == 3)//cleared space
                {
                    ofSetColor(0,255,0);
                    int greenx =(i % 20)*25;
                    int greeny = (i/20)*25;
                    ofRect(greenx,greeny,23,23);
                    int totalmines = MineNumber(i+1);
                    ofSetColor(0,0,0);
                    ofDrawBitmapString(ofToString(totalmines,0),greenx+8,greeny+16);
                }
            else if (minemap[i+1] >= 4)//flag
                {
                    ofSetColor(255,255,0);
                    ofRect((i % 20)*25,(i/20)*25,23,23);
                }

        }
    if (gameover == 1)
        {
            ofSetColor(0,0,0);
            ofDrawBitmapString("GAMEOVER!!! " , 220, 220);
        }
    if (winning == 1)
        {
            ofSetColor(0,0,0);
            ofDrawBitmapString("YOU WIN!!!! " , 220, 220);
        }
        time2 = time(NULL)-time1;

    ofSetColor(0,0,0);
    ofDrawBitmapString("Time: " + ofToString(time2) , 200,550 );
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    if (button == 0) MinePick(x,y);
    if (button == 2) MineFlag(x,y);
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
