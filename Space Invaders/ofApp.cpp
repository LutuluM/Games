#include "ofApp.h"
#include <time.h>

/*
0 - Free space
1 - Player Character
2 - Bullets
3 - Enemy
*/
void ofApp::enemy()
{
int i,k;
int n=121;
if (enemyDirection == 1)
    {
     for (i=0;i<3;i++)
    {
        for (k=0;k<10;k++)
        {
            n-=4;
            if (foes[i][k].active==1)
            {
                if(rand()%n==0 &&  foes[i][k].bullet.exist==0)
                {
                    foes[i][k].bullet.exist=1;
                    foes[i][k].bullet.y = foes[i][k].y+10;
                    foes[i][k].bullet.x = foes[i][k].x+10;
                    n=121;
                }
                if (foes[i][k].x<475)
                    {
                        foes[i][k].x += enemyDirection;
                    }
                else
                     {
                        enemyDirection = -1;
                        for(i=0;i<3;i++)
                        {
                            for (k=0;k<10;k++)
                            {
                                if(foes[i][k].active==1)
                                {
                                    foes[i][k].y += 20;
                                }
                            }
                        }
                        return;
                    }
            }
        }

        }
    }
else
    {
     for (i=0;i<3;i++)
    {
        for (k=0;k<10;k++)
        {
            n-=4;
            if (foes[i][k].active==1)
            {
                if(rand()%n==0 &&  foes[i][k].bullet.exist==0)
                {
                    n=121;
                    foes[i][k].bullet.exist=1;
                    foes[i][k].bullet.y = foes[i][k].y+10;
                    foes[i][k].bullet.x = foes[i][k].x+10;
                }
                if (foes[i][k].x>0)
                    {
                        foes[i][k].x += enemyDirection;
                    }
                else
                     {
                        enemyDirection = 1;
                        for(i=0;i<3;i++)
                        {
                            for (k=0;k<10;k++)
                            {
                                if(foes[i][k].active==1)
                                {
                                    foes[i][k].y += 20;
                                }
                            }
                        }
                    }
            }
        }

        }
}
}
void ofApp::bulletHit()
{
    int i,j,k;
    for (j=0;j<totalBullets;j++)
    {
    if(user.bullet[j].exist==1)
        {
        for (i=0;i<3;i++)
            {
            for(k=0;k<10;k++)
                {
                if (foes[i][k].active==1)
                    {
                    if((user.bullet[j].x <= foes[i][k].x+21) && (user.bullet[j].x >= foes[i][k].x-3) && (user.bullet[j].y >= foes[i][k].y) && (user.bullet[j].y <= foes[i][k].y+20))
                        {
                            user.bullet[j].exist=0;
                            foes[i][k].active=0;
                        }
                    }
                }
            }
        }
    }
    for (i=0;i<3;i++)
        {
            for(k=0;k<10;k++)
            {
                if (foes[i][k].bullet.exist==1)
                {
                    if(foes[i][k].bullet.x >= user.x && foes[i][k].bullet.x <= user.x+40 && foes[i][k].bullet.y>=user.y+2 && foes[i][k].bullet.y <= user.y+20)
                    {
                        foes[i][k].bullet.exist=0;
                        user.lives-=1;
                    }
                }
            }
        }
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    user.x=250;
    user.y=480;
    user.lives=5;
    int i,k;
    for (i=0;i<totalBullets;i++) user.bullet[i].exist=0;
    alien.loadImage("alien.png");
    bullet.loadImage("bullet.png");
    ofBackground(0,0,0);
    for(i=0;i<3;i++)
    {
        for (k=0;k<10;k++)
        {
            foes[i][k].active = 1;
            foes[i][k].x = k*50;
            foes[i][k].y = i*40;
            foes[i][k].bullet.exist=0;
        }
    }
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
    else if (user.x >= 460)
        {
            user.x =460;
            user.velx=0;
            user.velx1=0;
        }
    shipColor++;
    if (shipColor%3 == 0) ship.loadImage("ship1.png");
    else if (shipColor%3 == 1) ship.loadImage("ship2.png");
    else{ship.loadImage("ship3.png");shipColor=-1;enemy();}
    int i,k;
    for (i=0;i<totalBullets;i++)
    {
        if (user.bullet[i].y < 0) user.bullet[i].exist=0;
        else user.bullet[i].y -= 2;
    }
    for (i=0;i<3;i++)
    {
        for(k=0;k<10;k++)
            {
                if(foes[i][k].bullet.exist == 1)
                {
                    foes[i][k].bullet.y+=2;
                    if(foes[i][k].bullet.y>500)foes[i][k].bullet.exist=0;
                }
            }
    }
    bulletHit();
}
//--------------------------------------------------------------
void ofApp::draw(){
        if (user.lives<=0)ofSetColor(0,0,255);
        else ofSetColor(255,255,255);
        ship.draw(user.x,user.y,40,20);
        ofSetColor(255,255,255);
        ofDrawBitmapString("Lives:"+ofToString(user.lives),5,495);
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
        ofDrawBitmapString("Bullets:"+ofToString(20-count1),5,485);
        for (i=0;i<3;i++)
        {
            for(k=0;k<10;k++)
            {
                ofSetColor(255,255,255);
                if(foes[i][k].active == 1) alien.draw(foes[i][k].x,foes[i][k].y,25,20);
                ofSetColor(0,255,0);
                if(foes[i][k].bullet.exist == 1) bullet.draw(foes[i][k].bullet.x,foes[i][k].bullet.y,4,10);
            }
        }
}
//--------------------------------------------------------------
void ofApp::mousePressed(int a, int b, int button){
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'a')
    {
      user.velx = -1;
    }
    else if (key == 'd')
    {
        user.velx1 = 1;
    }
    else if (key == 'w')
    {
      user.vely = -1;
    }
    else if (key == 's')
    {
        user.vely1 = 1;
    }
    else if (key == ' ')
    {
        int i;
        for (i=0;i<totalBullets;i++)
        {
            if (user.bullet[i].exist==0)
            {
                user.bullet[i].x = user.x + 20;
                user.bullet[i].y = user.y;
                user.bullet[i].exist =1;
                break;
            }
        }
    }
    else if (key == 'r') setup();
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
