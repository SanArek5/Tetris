#pragma once
#include "PieceType.h"
class Tetromino {
private:
	PieceType type;
	int PieceTab[4][4];
	int x;
	int y;
public:
	Tetromino(PieceType type);
	void printPiece();
	int getX() const;
	int getY() const;
	const int(&getTab() const)[4][4];
	void move(int xx, int yy);
	void rotate();

};
