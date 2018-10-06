#include "ofApp.h"
#include <time.h>

#define Scale 20
#define fps 120
#define userSpeed 1
#define enemySpeed 12
#define totalBullets 20

void ofApp::enemy()
{
int i;
enemyLeft=0;
     for (i=0;i<20;i++)
    {
            if (foes[i].active==1)
            {
                if(foes[i].y<=500-5*Scale) foes[i].directionY=Scale;
                if(foes[i].y>=500-Scale) foes[i].directionY=-Scale;
                enemyLeft++;
                if ((foes[i].x<=0 && foes[i].direction<0) || (foes[i].x>=500-Scale && foes[i].direction>0) || (shrooms[(foes[i].x+foes[i].direction)/Scale][foes[i].y/Scale].active==1))
                    {
                        foes[i].y += foes[i].directionY;
                        foes[i].direction *= -1;
                        if (foes[i].direction<0)foes[i].alien.loadImage("alien1.png");
                        if (foes[i].direction>0)foes[i].alien.loadImage("alien3.png");
                    }
                else
                {
                    foes[i].x += foes[i].direction;
                    if((foes[i].x<=0 && foes[i].direction<0) || (foes[i].x>=500-Scale && foes[i].direction>0) || (shrooms[(foes[i].x+foes[i].direction)/Scale][foes[i].y/Scale].active==1))
                    {
                        if(foes[i].directionY>=0) foes[i].alien.loadImage("alien2.png");
                        else  foes[i].alien.loadImage("alien4.png");
                    }
                }
            }
    }
    if (enemyLeft==0) {score+=500;centRespawn();}
}

void ofApp::bulletHit()
{
    int i,j,x,y;
    for (j=0;j<totalBullets;j++)
    {
    if(user.bullet[j].exist==1)
        {
        for (i=0;i<20;i++)
            {
                if (foes[i].active==1)
                    {
                    if((user.bullet[j].x <= foes[i].x+Scale) && (user.bullet[j].x >= foes[i].x-3) && (user.bullet[j].y >= foes[i].y) && (user.bullet[j].y <= foes[i].y+20))
                        {
                            user.bullet[j].exist=0;
                            foes[i].active=0;
                            shrooms[foes[i].x/Scale][foes[i].y/Scale].active=1;
                            score+=100;
                            goto mush;
                        }
                    }
            }
        mush:
        x=user.bullet[j].x/Scale;
        y=user.bullet[j].y/Scale;
        if(shrooms[x][y].active==1 && user.bullet[j].exist==1)
                        {
                            user.bullet[j].exist=0;
                            shrooms[x][y].state++;
                            switch(shrooms[x][y].state)
                            {
                            case 2:
                                shrooms[x][y].shroom.loadImage("shroom2.png");
                                score+=10;
                                break;
                            case 3:
                                shrooms[x][y].shroom.loadImage("shroom3.png");
                                score+=10;
                                break;
                            case 4:
                                shrooms[x][y].shroom.loadImage("shroom4.png");
                                score+=10;
                                break;
                            case 5:
                                shrooms[x][y].shroom.loadImage("shroom1.png");
                                shrooms[x][y].state=1;
                                shrooms[x][y].active=0;
                                score+=20;
                                break;
                            }
                        }
        }
    }
}
void ofApp::centRespawn()
{
    int i,k=rand()%2-2;
    for(i=0;i<20;i++)
    {
            foes[i].active = 1;
            foes[i].x = i*Scale;
            foes[i].y = k*Scale;
            foes[i].direction=Scale;
            foes[i].directionY=Scale;
            foes[i].alien.loadImage("alien3.png");
    }
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(fps);
    user.x=250;
    user.y=480;
    user.lives=3;
    enemyMove=0;
    score=0;
    int i,k;
    for (i=0;i<totalBullets;i++) user.bullet[i].exist=0;
    bullet.loadImage("bullet.png");
    ship.loadImage("ship.png");
    ofBackground(0,0,0);
    for (i=0;i<25;i++)
    {
        for (k=0;k<25;k++)
        {
            shrooms[i][k].x=i*Scale;
            shrooms[i][k].y=k*Scale;
            shrooms[i][k].active=0;
            shrooms[i][k].shroom.loadImage("shroom1.png");
            shrooms[i][k].state=1;
        }
    }
    for(i=0;i<75;i++) shrooms[rand()%25][rand()%20].active=1;
    centRespawn();
}
//--------------------------------------------------------------
void ofApp::update(){
    user.x += user.velx + user.velx1;
    user.y += user.vely + user.vely1;
    if (user.x <= 0)
        {
            user.x=0;
            user.velx=0;
            user.velx1=0;
        }
    else if (user.x >= 500-Scale)
        {
            user.x =500-Scale;
            user.velx=0;
            user.velx1=0;
        }
    enemyMove++;
    if (enemyMove>fps/(enemySpeed)){enemy();enemyMove=0;}
    int i;
    for (i=0;i<totalBullets;i++)
    {
        user.bullet[i].y -= 5;
        if (user.bullet[i].y < 4) user.bullet[i].exist=0;
    }
    bulletHit();
}
//--------------------------------------------------------------
void ofApp::draw(){
        if (user.lives<=0)ofSetColor(0,0,255);
        else ofSetColor(255,255,255);
        ship.draw(user.x,user.y,Scale,Scale);

        ofSetColor(255,255,255);
        ofDrawBitmapString("Lives:"+ofToString(user.lives),5,495);
        ofDrawBitmapString("FPS:"+ofToString((int)ofGetFrameRate()),5,485);
        ofDrawBitmapString("Score:"+ofToString(score),5,475);
        int i,k;
        int count1=0;
        for (i=0;i<totalBullets;i++)
        {
            if(user.bullet[i].exist==1)
            {
                bullet.draw(user.bullet[i].x,user.bullet[i].y,4,4);
                count1++;
            }
        }
        for (i=0;i<25;i++)
        {
            for (k=0;k<25;k++)
            {
                if(shrooms[i][k].active==1) shrooms[i][k].shroom.draw(i*Scale,k*Scale,Scale,Scale);
            }
        }
        for (i=0;i<20;i++)
        {
                if(foes[i].active == 1) foes[i].alien.draw(foes[i].x,foes[i].y,Scale,Scale);
        }
}
//--------------------------------------------------------------
void ofApp::mousePressed(int a, int b, int button){
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'a')
    {
      user.velx = -userSpeed;
    }
    else if (key == 'd')
    {
        user.velx1 = userSpeed;
    }
    else if (key == 'w')
    {
      user.vely = -userSpeed;
    }
    else if (key == 's')
    {
        user.vely1 = userSpeed;
    }
    else if (key == ' ')
    {
        int i;
        for (i=0;i<totalBullets;i++)
        {
            if (user.bullet[i].exist==0)
            {
                user.bullet[i].x = user.x + Scale/2;
                user.bullet[i].y = user.y;
                user.bullet[i].exist =1;
                break;
            }
        }
    }
    else if (key == 'r') centRespawn();
    else if (key == 'R') setup();
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'a')
        {
          user.velx = 0;
        }
    if (key == 'd')
        {
          user.velx1 = 0;
        }
    if (key == 'w')
    {
      user.vely = 0;
    }
    if (key == 's')
    {
        user.vely1 = 0;
    }
}
