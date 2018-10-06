#include "ofApp.h"
#include <time.h>
/*
Number References
0 - blank space
1 - white pawn
2 - white rook
3 - white knight
4 - white bishop
5 - white queen
6 - white king
7 - white king NO CASTLE
8 - white rook NO CASTLE
11 - black pawn
12 - black rook
13 - black knight
14 - black bishop
15 - black queen
16 - black king
17 - black king NO CASTLE
18 - white rook NO CASTLE
1 selected
2 move
3 attack
THINGS TO DO EVENTUALLY
pawn capture when moving double;check,checkmate,stalemate;highlighting and other pieces
*/
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::initBoard()
{
    //Set white move first
    turnOrder=0;
    //Clear highlights and the board
    int i;
    int k;
    for(i=0;i<8;i++)
    {
        for (k=0; k<8;k++)
        {
            boardHighlight[i][k]=0;
            board[i][k]=0;
        }
    }
    //Pawns
    for (i =0; i < 8; i++)
    {
      board[i][1] = 1;
      board[i][6] = 11;
    }
    //Rooks
    board[0][0] = 2;
    board[7][0] = 2;
    board[0][7] = 12;
    board[7][7] = 12;
    //Knights
    board[1][0] = 3;
    board[6][0] = 3;
    board[1][7] = 13;
    board[6][7] = 13;
    //Bishops
    board[2][0] = 4;
    board[5][0] = 4;
    board[2][7] = 14;
    board[5][7] = 14;
    //Kings & Queens
    board[3][0] = 6;
    board[4][0] = 5;
    board[3][7] = 16;
    board[4][7] = 15;

    //Timers
    timeWhite = 0;
	timeBlack = 0;

	//value of the winner
	winner = 0;

    //Graphics
    whitePawn.loadImage("white.pawn.png");
    whiteRook.loadImage("white.rook.png");
    whiteKnight.loadImage("white.knight.png");
    whiteBishop.loadImage("white.bishop.png");
    whiteQueen.loadImage("white.queen.png");
    whiteKing.loadImage("white.king.png");
    blackPawn.loadImage("black.pawn.png");
    blackRook.loadImage("black.rook.png");
    blackKnight.loadImage("black.knight.png");
    blackBishop.loadImage("black.bishop.png");
    blackQueen.loadImage("black.queen.png");
    blackKing.loadImage("black.king.png");
    castleLeft.loadImage("castle.left.png");
    castleRight.loadImage("castle.right.png");
    turnBanner.loadImage("turn.png");
    whiteWins.loadImage("whitewins.png");
    blackWins.loadImage("blackwins.png");
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::drawPieces()
{
    int i;
    int k;
    ofSetColor(255,255,255);
    whiteBishop.update();
    for (i=0; i<8; i++)
    {
        for (k=0; k<8; k++)
            {
                if (board[i][k] == 1)       whitePawn.draw(i*75+15,k*75+15,45,45);
                else if (board[i][k] == 2)  whiteRook.draw(i*75+15,k*75+15,45,45);
                else if (board[i][k] == 3)  whiteKnight.draw(i*75+15,k*75+15,45,45);
                else if (board[i][k] == 4)  whiteBishop.draw(i*75+15,k*75+15,45,45);
                else if (board[i][k] == 5)  whiteQueen.draw(i*75+15,k*75+15,45,45);
                else if (board[i][k] == 6)  whiteKing.draw(i*75+15,k*75+15,45,45);
                else if (board[i][k] == 7)  whiteKing.draw(i*75+15,k*75+15,45,45);
                else if (board[i][k] == 8)  whiteRook.draw(i*75+15,k*75+15,45,45);

                else if (board[i][k] == 11) blackPawn.draw(i*75+15,k*75+15,45,45);
                else if (board[i][k] == 12) blackRook.draw(i*75+15,k*75+15,45,45);
                else if (board[i][k] == 13) blackKnight.draw(i*75+15,k*75+15,45,45);
                else if (board[i][k] == 14) blackBishop.draw(i*75+15,k*75+15,45,45);
                else if (board[i][k] == 15) blackQueen.draw(i*75+15,k*75+15,45,45);
                else if (board[i][k] == 16) blackKing.draw(i*75+15,k*75+15,45,45);
                else if (board[i][k] == 17) blackKing.draw(i*75+15,k*75+15,45,45);
                else if (board[i][k] == 18) blackRook.draw(i*75+15,k*75+15,45,45);
            }
    }
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::drawBoard()
{
    int i;
    int k;
    for (i=0; i<8; i++)
    {
        for (k=0; k<8; k++)
        {
            if((i+k)%2 == 0)        //white tiles
            {
                ofSetColor(200,200,150);
                ofRect(i*75,k*75,75,75);
            }
            else if((i+k)%2 == 1)   //brown tiles
            {
                ofSetColor(100,50,50);
                ofRect(i*75,k*75,75,75);
            }
            if (boardHighlight[i][k] == 1)
                {
                    ofSetColor(0,0,255);
                    ofRect(i*75,k*75,75,75);
                }
            else if (boardHighlight[i][k] == 2)
                {
                    ofSetColor(0,255,0);
                    ofRect(i*75,k*75,75,75);
                }
            else if (boardHighlight[i][k] == 3)
                {
                    ofSetColor(255,0,0);
                    ofRect(i*75,k*75,75,75);
                }
            else
                {
                    ofSetColor(0,0,0,0);
                    ofRect(i*75,k*75,75,75);
                }
        }
    }
    ofSetColor(255,255,255);
    castleLeft.draw(600,0);
    castleRight.draw(700,0);
    castleLeft.draw(600,525);
    castleRight.draw(700,525);
    if (turnOrder == 0) turnBanner.draw(600,75);
    else turnBanner.draw(600,450);
    if (winner == 1) whiteWins.draw(600,225);
    if (winner == -1) blackWins.draw(600,225);

}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::clearHighlight()
{
int k;
       int i;
       for(i=0;i<16;i++)
            {
            for (k=0; k<16;k++)
            {
            boardHighlight[i][k]=0;
            }
        }
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::pawnMove(int x, int y)
{
    if(boardHighlight[x][y]>1)
    {
       board[x][y]=board[selected[0]][selected[1]];
       board[selected[0]][selected[1]]=0;
       clearHighlight();
       victory();
       turnOrder = (turnOrder+1)%2;
       if (y==0) board[x][y] = 15;
       if (y==7) board[x][y] = 5;
    }
    else if (board[x][y] == 1)
    {
        if (y==1 && board[x][y+1]==0 && board[x][y+2]==0)
        {
            boardHighlight[x][y+1]=2;
            boardHighlight[x][y+2]=2;
        }
        if (board[x][y+1]==0)
        {
            boardHighlight[x][y+1]=2;
        }
        if (board[x+1][y+1]>10)
        {
            boardHighlight[x+1][y+1]=3;
        }
        if (board[x-1][y+1]>10)
        {
            boardHighlight[x-1][y+1]=3;
        }
    }
    else if (board[x][y] == 11)
    {
        if (y==6 && board[x][y-1]==0 && board[x][y-2]==0)
        {
            boardHighlight[x][y-1]=2;
            boardHighlight[x][y-2]=2;
        }
        if (board[x][y-1]==0)
        {
            boardHighlight[x][y-1]=2;
        }
        if (0 < board[x+1][y-1] && board[x+1][y-1]<10)
        {
            boardHighlight[x+1][y-1]=3;
        }
        if (0 < board[x-1][y-1] && board[x-1][y-1]<10)
        {
            boardHighlight[x-1][y-1]=3;
        }
    }
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::knightMove(int x, int y)
{
    if(boardHighlight[x][y]>1)
    {
       board[x][y]=board[selected[0]][selected[1]];
       board[selected[0]][selected[1]]=0;
       turnOrder = (turnOrder+1)%2;
       clearHighlight();
       victory();
    }
    else if (board[x][y] == 3)
    {
        if (board[x+1][y+2] == 0) boardHighlight[x+1][y+2] = 2;
        if (board[x+2][y+1] == 0) boardHighlight[x+2][y+1] = 2;
        if (board[x-1][y+2] == 0) boardHighlight[x-1][y+2] = 2;
        if (board[x-2][y+1] == 0) boardHighlight[x-2][y+1] = 2;
        if (board[x+1][y-2] == 0) boardHighlight[x+1][y-2] = 2;
        if (board[x+2][y-1] == 0) boardHighlight[x+2][y-1] = 2;
        if (board[x-1][y-2] == 0) boardHighlight[x-1][y-2] = 2;
        if (board[x-2][y-1] == 0) boardHighlight[x-2][y-1] = 2;

        if (board[x+1][y+2] > 10) boardHighlight[x+1][y+2] = 3;
        if (board[x+2][y+1] > 10) boardHighlight[x+2][y+1] = 3;
        if (board[x-1][y+2] > 10) boardHighlight[x-1][y+2] = 3;
        if (board[x-2][y+1] > 10) boardHighlight[x-2][y+1] = 3;
        if (board[x+1][y-2] > 10) boardHighlight[x+1][y-2] = 3;
        if (board[x+2][y-1] > 10) boardHighlight[x+2][y-1] = 3;
        if (board[x-1][y-2] > 10) boardHighlight[x-1][y-2] = 3;
        if (board[x-2][y-1] > 10) boardHighlight[x-2][y-1] = 3;
    }
    else if (board[x][y] == 13)
    {
        if (board[x+1][y+2] == 0) boardHighlight[x+1][y+2] = 2;
        if (board[x+2][y+1] == 0) boardHighlight[x+2][y+1] = 2;
        if (board[x-1][y+2] == 0) boardHighlight[x-1][y+2] = 2;
        if (board[x-2][y+1] == 0) boardHighlight[x-2][y+1] = 2;
        if (board[x+1][y-2] == 0) boardHighlight[x+1][y-2] = 2;
        if (board[x+2][y-1] == 0) boardHighlight[x+2][y-1] = 2;
        if (board[x-1][y-2] == 0) boardHighlight[x-1][y-2] = 2;
        if (board[x-2][y-1] == 0) boardHighlight[x-2][y-1] = 2;

        if (board[x+1][y+2] < 10 && board[x+1][y+2] > 0) boardHighlight[x+1][y+2] = 3;
        if (board[x+2][y+1] < 10 && board[x+2][y+1] > 0) boardHighlight[x+2][y+1] = 3;
        if (board[x-1][y+2] < 10 && board[x-1][y+2] > 0) boardHighlight[x-1][y+2] = 3;
        if (board[x-2][y+1] < 10 && board[x-2][y+1] > 0) boardHighlight[x-2][y+1] = 3;
        if (board[x+1][y-2] < 10 && board[x+1][y-2] > 0) boardHighlight[x+1][y-2] = 3;
        if (board[x+2][y-1] < 10 && board[x+2][y-1] > 0) boardHighlight[x+2][y-1] = 3;
        if (board[x-1][y-2] < 10 && board[x-1][y-2] > 0) boardHighlight[x-1][y-2] = 3;
        if (board[x-2][y-1] < 10 && board[x-2][y-1] > 0) boardHighlight[x-2][y-1] = 3;
    }
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::kingMove(int x, int y)
{
    if(boardHighlight[x][y]>1)
    {
       board[x][y]=board[selected[0]][selected[1]];
       board[selected[0]][selected[1]]=0;
       clearHighlight();
       victory();
       turnOrder = (turnOrder+1)%2;
       if (board[x][y]==6) board[x][y]=7;
       if (board[x][y]==16) board[x][y]=17;
    }
    else if (board[x][y] == 6 || board[x][y] == 7)
    {
        if (board[x+1][y] == 0) boardHighlight[x+1][y] = 2;
        if (board[x][y+1] == 0) boardHighlight[x][y+1] = 2;
        if (board[x-1][y] == 0) boardHighlight[x-1][y] = 2;
        if (board[x][y-1] == 0) boardHighlight[x][y-1] = 2;
        if (board[x+1][y+1] == 0) boardHighlight[x+1][y+1] = 2;
        if (board[x+1][y-1] == 0) boardHighlight[x+1][y-1] = 2;
        if (board[x-1][y-1] == 0) boardHighlight[x-1][y-1] = 2;
        if (board[x-1][y+1] == 0) boardHighlight[x-1][y+1] = 2;

        if (board[x+1][y] > 10) boardHighlight[x+1][y] = 3;
        if (board[x][y+1] > 10) boardHighlight[x][y+1] = 3;
        if (board[x-1][y] > 10) boardHighlight[x-1][y] = 3;
        if (board[x][y-1] > 10) boardHighlight[x][y-1] = 3;
        if (board[x+1][y+1] > 10) boardHighlight[x+1][y+1] = 3;
        if (board[x+1][y-1] > 10) boardHighlight[x+1][y-1] = 3;
        if (board[x-1][y-1] > 10) boardHighlight[x-1][y-1] = 3;
        if (board[x-1][y+1] > 10) boardHighlight[x-1][y+1] = 3;
    }
    else if (board[x][y] == 16 || board[x][y] == 17)
    {
        if (board[x+1][y] == 0) boardHighlight[x+1][y] = 2;
        if (board[x][y+1] == 0) boardHighlight[x][y+1] = 2;
        if (board[x-1][y] == 0) boardHighlight[x-1][y] = 2;
        if (board[x][y-1] == 0) boardHighlight[x][y-1] = 2;
        if (board[x+1][y+1] == 0) boardHighlight[x+1][y+1] = 2;
        if (board[x+1][y-1] == 0) boardHighlight[x+1][y-1] = 2;
        if (board[x-1][y-1] == 0) boardHighlight[x-1][y-1] = 2;
        if (board[x-1][y+1] == 0) boardHighlight[x-1][y+1] = 2;

        if (board[x+1][y] < 10 && board[x+1][y] > 0) boardHighlight[x+1][y] = 3;
        if (board[x][y+1] < 10 && board[x][y+1] > 0) boardHighlight[x][y+1] = 3;
        if (board[x-1][y] < 10 && board[x-1][y] > 0) boardHighlight[x-1][y] = 3;
        if (board[x][y-1] < 10 && board[x][y-1] > 0) boardHighlight[x][y-1] = 3;
        if (board[x+1][y+1] < 10 && board[x+1][y+1] > 0) boardHighlight[x+1][y+1] = 3;
        if (board[x+1][y-1] < 10 && board[x+1][y-1] > 0) boardHighlight[x+1][y-1] = 3;
        if (board[x-1][y-1] < 10 && board[x-1][y-1] > 0) boardHighlight[x-1][y-1] = 3;
        if (board[x-1][y+1] < 10 && board[x-1][y+1] > 0) boardHighlight[x-1][y+1] = 3;
    }
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::rookMove(int x, int y)
{
    if(boardHighlight[x][y]>1)
    {
       board[x][y]=board[selected[0]][selected[1]];
       board[selected[0]][selected[1]]=0;
       clearHighlight();
       victory();
       turnOrder = (turnOrder+1)%2;
       if (board[x][y]==2) board[x][y]=8;
       if (board[x][y]==12) board[x][y]=18;
    }
    else if (board[x][y] == 2 || board[x][y] == 8)
    {
        int i;
        for (i=1;i+x<8;i++)
        {
            if (board[x+i][y] == 0) boardHighlight[x+i][y] = 2;
            if (board[x+i][y] > 10)
            {
                boardHighlight[x+i][y] = 3;
                break;
            }
            if (board[x+i][y] != 0) break;
        }
        for (i=1;i+y<8;i++)
        {
            if (board[x][y+i] == 0) boardHighlight[x][y+i] = 2;
            if (board[x][y+i] > 10)
            {
                boardHighlight[x][y+i] = 3;
                break;
            }
            if (board[x][y+i] != 0) break;
        }
        for (i=1;x-i>-1;i++)
        {
            if (board[x-i][y] == 0) boardHighlight[x-i][y] = 2;
            if (board[x-i][y] > 10)
            {
                boardHighlight[x-i][y] = 3;
                break;
            }
            if (board[x-i][y] != 0) break;
        }
        for (i=1;y-i>-1;i++)
        {
            if (board[x][y-i] == 0) boardHighlight[x][y-i] = 2;
            if (board[x][y-i] > 10)
            {
                boardHighlight[x][y-i] = 3;
                break;
            }
            if (board[x][y-i] != 0) break;
        }
    }
    else if (board[x][y] == 12 || board[x][y] == 18)
    {
        int i;
        for (i=1;i+x<8;i++)
        {
            if (board[x+i][y] == 0) boardHighlight[x+i][y] = 2;
            else if (board[x+i][y] < 10)
            {
                boardHighlight[x+i][y] = 3;
                break;
            }
            else if (board[x+i][y] != 0) break;
        }
        for (i=1;i+y<8;i++)
        {
            if (board[x][y+i] == 0) boardHighlight[x][y+i] = 2;
            else if (board[x][y+i] < 10)
            {
                boardHighlight[x][y+i] = 3;
                break;
            }
            else if (board[x][y+i] != 0) break;
        }
        for (i=1;x-i>-1;i++)
        {
            if (board[x-i][y] == 0) boardHighlight[x-i][y] = 2;
            else if (board[x-i][y] < 10)
            {
                boardHighlight[x-i][y] = 3;
                break;
            }
            else if (board[x-i][y] != 0) break;
        }
        for (i=1;y-i>-1;i++)
        {
            if (board[x][y-i] == 0) boardHighlight[x][y-i] = 2;
            else if (board[x][y-i] < 10)
            {
                boardHighlight[x][y-i] = 3;
                break;
            }
            else if (board[x][y-i] != 0) break;
        }
    }
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::bishopMove(int x, int y)
{
    if(boardHighlight[x][y]>1)
    {
       board[x][y]=board[selected[0]][selected[1]];
       board[selected[0]][selected[1]]=0;
       turnOrder = (turnOrder+1)%2;
       clearHighlight();
       victory();
    }
    else if (board[x][y] == 4)
    {
        int i;
        for (i=1;i+x<8 && i+y<8;i++)
        {
            if (board[x+i][y+i] == 0) boardHighlight[x+i][y+i] = 2;
            if (board[x+i][y+i] > 10)
            {
                boardHighlight[x+i][y+i] = 3;
                break;
            }
            if (board[x+i][y+i] != 0) break;
        }
        for (i=1;x-i>-1 && i+y<8;i++)
        {
            if (board[x-i][y+i] == 0) boardHighlight[x-i][y+i] = 2;
            if (board[x-i][y+i] > 10)
            {
                boardHighlight[x-i][y+i] = 3;
                break;
            }
            if (board[x-i][y+i] != 0) break;
        }
        for (i=1;x-i>-1 && y-i>-1;i++)
        {
            if (board[x-i][y-i] == 0) boardHighlight[x-i][y-i] = 2;
            if (board[x-i][y-i] > 10)
            {
                boardHighlight[x-i][y-i] = 3;
                break;
            }
            if (board[x-i][y-i] != 0) break;
        }
        for (i=1;i+x<8 && y-i>-1;i++)
        {
            if (board[x+i][y-i] == 0) boardHighlight[x+i][y-i] = 2;
            if (board[x+i][y-i] > 10)
            {
                boardHighlight[x+i][y-i] = 3;
                break;
            }
            if (board[x+i][y-i] != 0) break;
        }
    }
    else if (board[x][y] == 14)
    {
        int i;
        for (i=1;i+x<8 && i+y<8;i++)
        {
            if (board[x+i][y+i] == 0) boardHighlight[x+i][y+i] = 2;
            else if (board[x+i][y+i] < 10)
            {
                boardHighlight[x+i][y+i] = 3;
                break;
            }
            else if (board[x+i][y+i] != 0) break;
        }
        for (i=1;x-i>-1 && i+y<8;i++)
        {
            if (board[x-i][y+i] == 0) boardHighlight[x-i][y+i] = 2;
            else if (board[x-i][y+i] < 10)
            {
                boardHighlight[x-i][y+i] = 3;
                break;
            }
            else if (board[x-i][y+i] != 0) break;
        }
        for (i=1;x-i>-1 && y-i>-1;i++)
        {
            if (board[x-i][y-i] == 0) boardHighlight[x-i][y-i] = 2;
            else if (board[x-i][y-i] < 10)
            {
                boardHighlight[x-i][y-i] = 3;
                break;
            }
            else if (board[x-i][y-i] != 0) break;
        }
        for (i=1;i+x<8 && y-i>-1;i++)
        {
            if (board[x+i][y-i] == 0) boardHighlight[x+i][y-i] = 2;
            else if (board[x+i][y-i] < 10)
            {
                boardHighlight[x+i][y-i] = 3;
                break;
            }
            else if (board[x+i][y-i] != 0) break;
        }

    }
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::queenMove(int x, int y)
{
    if(boardHighlight[x][y]>1)
    {
       board[x][y]=board[selected[0]][selected[1]];
       board[selected[0]][selected[1]]=0;
       turnOrder = (turnOrder+1)%2;
       clearHighlight();
       victory();
    }
    else if (board[x][y] == 5)
    {
        int i;
        for (i=1;i+x<8;i++)
        {
            if (board[x+i][y] == 0) boardHighlight[x+i][y] = 2;
            if (board[x+i][y] > 10)
            {
                boardHighlight[x+i][y] = 3;
                break;
            }
            if (board[x+i][y] != 0) break;
        }
        for (i=1;i+y<8;i++)
        {
            if (board[x][y+i] == 0) boardHighlight[x][y+i] = 2;
            if (board[x][y+i] > 10)
            {
                boardHighlight[x][y+i] = 3;
                break;
            }
            if (board[x][y+i] != 0) break;
        }
        for (i=1;x-i>-1;i++)
        {
            if (board[x-i][y] == 0) boardHighlight[x-i][y] = 2;
            if (board[x-i][y] > 10)
            {
                boardHighlight[x-i][y] = 3;
                break;
            }
            if (board[x-i][y] != 0) break;
        }
        for (i=1;y-i>-1;i++)
        {
            if (board[x][y-i] == 0) boardHighlight[x][y-i] = 2;
            if (board[x][y-i] > 10)
            {
                boardHighlight[x][y-i] = 3;
                break;
            }
            if (board[x][y-i] != 0) break;
        }
        for (i=1;i+x<8 && i+y<8;i++)
        {
            if (board[x+i][y+i] == 0) boardHighlight[x+i][y+i] = 2;
            if (board[x+i][y+i] > 10)
            {
                boardHighlight[x+i][y+i] = 3;
                break;
            }
            if (board[x+i][y+i] != 0) break;
        }
        for (i=1;x-i>-1 && i+y<8;i++)
        {
            if (board[x-i][y+i] == 0) boardHighlight[x-i][y+i] = 2;
            if (board[x-i][y+i] > 10)
            {
                boardHighlight[x-i][y+i] = 3;
                break;
            }
            if (board[x-i][y+i] != 0) break;
        }
        for (i=1;x-i>-1 && y-i>-1;i++)
        {
            if (board[x-i][y-i] == 0) boardHighlight[x-i][y-i] = 2;
            if (board[x-i][y-i] > 10)
            {
                boardHighlight[x-i][y-i] = 3;
                break;
            }
            if (board[x-i][y-i] != 0) break;
        }
        for (i=1;i+x<8 && y-i>-1;i++)
        {
            if (board[x+i][y-i] == 0) boardHighlight[x+i][y-i] = 2;
            if (board[x+i][y-i] > 10)
            {
                boardHighlight[x+i][y-i] = 3;
                break;
            }
            if (board[x+i][y-i] != 0) break;
        }
    }
    else if (board[x][y] == 15)
    {
        int i;
        for (i=1;i+x<8;i++)
        {
            if (board[x+i][y] == 0) boardHighlight[x+i][y] = 2;
            else if (board[x+i][y] < 10)
            {
                boardHighlight[x+i][y] = 3;
                break;
            }
            else if (board[x+i][y] != 0) break;
        }
        for (i=1;i+y<8;i++)
        {
            if (board[x][y+i] == 0) boardHighlight[x][y+i] = 2;
            else if (board[x][y+i] < 10)
            {
                boardHighlight[x][y+i] = 3;
                break;
            }
            else if (board[x][y+i] != 0) break;
        }
        for (i=1;x-i>-1;i++)
        {
            if (board[x-i][y] == 0) boardHighlight[x-i][y] = 2;
            else if (board[x-i][y] < 10)
            {
                boardHighlight[x-i][y] = 3;
                break;
            }
            else if (board[x-i][y] != 0) break;
        }
        for (i=1;y-i>-1;i++)
        {
            if (board[x][y-i] == 0) boardHighlight[x][y-i] = 2;
            else if (board[x][y-i] < 10)
            {
                boardHighlight[x][y-i] = 3;
                break;
            }
            else if (board[x][y-i] != 0) break;
        }
        for (i=1;i+x<8 && i+y<8;i++)
        {
            if (board[x+i][y+i] == 0) boardHighlight[x+i][y+i] = 2;
            else if (board[x+i][y+i] < 10)
            {
                boardHighlight[x+i][y+i] = 3;
                break;
            }
            else if (board[x+i][y+i] != 0) break;
        }
        for (i=1;x-i>-1 && i+y<8;i++)
        {
            if (board[x-i][y+i] == 0) boardHighlight[x-i][y+i] = 2;
            else if (board[x-i][y+i] < 10)
            {
                boardHighlight[x-i][y+i] = 3;
                break;
            }
            else if (board[x-i][y+i] != 0) break;
        }
        for (i=1;x-i>-1 && y-i>-1;i++)
        {
            if (board[x-i][y-i] == 0) boardHighlight[x-i][y-i] = 2;
            else if (board[x-i][y-i] < 10)
            {
                boardHighlight[x-i][y-i] = 3;
                break;
            }
            else if (board[x-i][y-i] != 0) break;
        }
        for (i=1;i+x<8 && y-i>-1;i++)
        {
            if (board[x+i][y-i] == 0) boardHighlight[x+i][y-i] = 2;
            else if (board[x+i][y-i] < 10)
            {
                boardHighlight[x+i][y-i] = 3;
                break;
            }
            else if (board[x+i][y-i] != 0) break;
        }

    }
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::castle(int x, int y)
{
    if (y < 100)
    {
        if (x < 700)
        {
            if (board[0][0] == 2 && board[1][0] == 0 && board[2][0] == 0 && board[3][0] == 6)
            {
                board[0][0]=0;
                board[3][0]=0;
                board[2][0]=8;
                board[1][0]=7;
                turnOrder = (turnOrder+1)%2;
            }
        }
        else if (x > 700)
        {
            if (board[3][0] == 6 && board[4][0] == 0 && board[5][0] == 0 && board[6][0] == 0 && board[7][0] == 2)
            {
                board[3][0]=0;
                board[7][0]=0;
                board[4][0]=8;
                board[5][0]=7;
                turnOrder = (turnOrder+1)%2;
            }
        }
    }
    else if (y > 500)
    {
        if (x < 700)
        {
            if (board[0][7] == 12 && board[1][7] == 0 && board[2][7] == 0 && board[3][7] == 16)
            {
                board[0][7]=0;
                board[3][7]=0;
                board[2][7]=18;
                board[1][7]=17;
                turnOrder = (turnOrder+1)%2;
            }
        }
        else if (x > 700)
        {
            if (board[3][7] == 16 && board[4][7] == 0 && board[5][7] == 0 && board[6][7] == 0 && board[7][7] == 12)
            {
                board[3][7]=0;
                board[7][7]=0;
                board[4][7]=18;
                board[5][7]=17;
                turnOrder = (turnOrder+1)%2;
            }
        }
    }
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::victory()
{
    int kingBlack = 0;
    int kingWhite = 0;
    int i;
    int k;
    for(i=0;i<8;i++)
    {
        for (k=0; k<8;k++)
        {
            if (board[i][k] == 6 || board[i][k] == 7) kingWhite = 1;
            else if (board[i][k] == 16 || board[i][k] == 17) kingBlack = 1;
        }
    }
    if (kingWhite == 0 && winner==0) winner = -1;
    else if (kingBlack == 0 && winner==0) winner = 1;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//--------------------------------------------------------------
void ofApp::setup(){
    srand(time(NULL));
    ofBackground(166,38,158);
    ofSetFrameRate(60);
    initBoard();
}
//--------------------------------------------------------------
void ofApp::update(){
    if (turnOrder == 0 && winner == 0) timeWhite += 1;
    else if (winner == 0)timeBlack +=1;

}
//--------------------------------------------------------------
void ofApp::draw(){
    drawBoard();
    drawPieces();
    ofSetColor(0,0,0);
    ofDrawBitmapString("White Timer:" + ofToString(timeWhite/60),625,175);
    ofDrawBitmapString("Black Timer:" + ofToString(timeBlack/60),625,425);
}
//--------------------------------------------------------------
void ofApp::mousePressed(int a, int b, int button){
    int x;
    int y;
    x = a/75;
    y = b/75;

    if (button==0)
    {
        if (turnOrder==0)
        {
            if ((600<a && a<800) && (0<b && b<75)) castle(a,b);
            else
            {
                if (boardHighlight[x][y] == 0)
                {
                    clearHighlight();
                    boardHighlight[x][y]=1;
                }
                if (board[selected[0]][selected[1]]== 1 || board[x][y]== 1) pawnMove(x,y);
                else if (board[selected[0]][selected[1]]== 2 || board[selected[0]][selected[1]]== 8 || board[x][y]== 2 || board[x][y]== 8) rookMove(x,y);
                else if (board[selected[0]][selected[1]]== 3 || board[x][y]== 3) knightMove(x,y);
                else if (board[selected[0]][selected[1]]== 4 || board[x][y]== 4) bishopMove(x,y);
                else if (board[selected[0]][selected[1]]== 5 || board[x][y]== 5) queenMove(x,y);
                else if (board[selected[0]][selected[1]]== 6 || board[selected[0]][selected[1]]== 7 || board[x][y]== 6 || board[x][y]== 7) kingMove(x,y);
                selected[0]=x;
                selected[1]=y;
            }
        }
        else
        {
            if ((600<a && a<800) && ((0<b && b<75)||(525<b && b<600))) castle(a,b);
            else
            {
                if (boardHighlight[x][y] == 0)
                {
                    clearHighlight();
                    boardHighlight[x][y]=1;
                }
                if (board[selected[0]][selected[1]]== 11 || board[x][y]== 11) pawnMove(x,y);
                else if (board[selected[0]][selected[1]]== 12 || board[selected[0]][selected[1]]== 18 || board[x][y]== 12 || board[x][y]== 18) rookMove(x,y);
                else if (board[selected[0]][selected[1]]== 13 || board[x][y]== 13) knightMove(x,y);
                else if (board[selected[0]][selected[1]]== 14 || board[x][y]== 14) bishopMove(x,y);
                else if (board[selected[0]][selected[1]]== 15 || board[x][y]== 15) queenMove(x,y);
                else if (board[selected[0]][selected[1]]== 16 || board[selected[0]][selected[1]]== 17 || board[x][y]== 16 || board[x][y]== 17) kingMove(x,y);
                selected[0]=x;
                selected[1]=y;
            }
        }
    }
    if (button == 2) clearHighlight();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'a')
    {
        int i;
        int k;
        for (i=0; i<8; i++)
            {
                printf("\n|");
                for (k=0; k<8; k++) printf("%d|",board[k][i]);
            }
    }
    if (key == 'r')
    {
        initBoard();
    }
}
//--------------------------------------------------------------
