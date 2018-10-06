#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
	    void drawBoard();
	    void initBoard();
	    void drawPieces();
	    void clearHighlight();
	    void pawnMove(int x, int y);
	    void knightMove(int x, int y);
	    void kingMove(int x, int y);
	    void rookMove(int x, int y);
	    void bishopMove(int x, int y);
	    void queenMove(int x, int y);
	    void castle(int x, int y);
	    void victory();
	    int winner;
	    int board[16][16];
	    int boardHighlight[16][16];
	    int selected[2];
	    int turnOrder;
	    int timeWhite;
	    int timeBlack;
	    ofImage whitePawn;
	    ofImage whiteRook;
	    ofImage whiteKnight;
	    ofImage whiteBishop;
	    ofImage whiteKing;
	    ofImage whiteQueen;
	    ofImage blackPawn;
	    ofImage blackRook;
	    ofImage blackKnight;
	    ofImage blackBishop;
	    ofImage blackKing;
	    ofImage blackQueen;
	    ofImage castleRight;
	    ofImage castleLeft;
	    ofImage turnBanner;
	    ofImage whiteWins;
	    ofImage blackWins;


		void setup();
		void update();
		void draw();
		void mousePressed(int x, int y, int button);
		void keyPressed(int key);
};
