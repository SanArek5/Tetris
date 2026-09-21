#pragma once
#include "Tetromino.h"
#include <SFML/Graphics.hpp>
class Board 
{
private:
	 int numRows;
	 int numCols;
	 int cellSize;
	 int** gameBoard;
public:
	Board();
	
	void printTab();
		~Board();
		void setCell(int row, int col, int value);
		int getCell(int row, int col);
		bool isRowFull(int row);
		void placePiece(const Tetromino& piece);
		void delPiece(const Tetromino& piece);
		void clearBoard();
		bool canMove(const Tetromino& piece, int dx, int dy);
		bool canRotate(const Tetromino& piece);
		void removeRow(int row);
		int clearFullRows();
		void draw(sf::RenderWindow& window) const;
		int getPixelWidth() const;
		int getPixelHeight() const;
};
