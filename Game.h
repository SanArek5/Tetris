#pragma once
#include<random>
#include"Board.h"
#include"Tetromino.h"
#include<SFML/Graphics.hpp>
class Game 
{
private:
	Board board;
	Tetromino currentPiece;
	PieceType nextPieceType;
	unsigned int score;
	bool gameover;
	std::mt19937 generator;
	PieceType getRandomPieceType();
	void drawSidePanel(sf::RenderWindow& window) const;
	void resetGame();
public:
	Game();
	void print();
	void moveDown();
	bool isGameOver() const;
	void run();
	void moveLeft();
	void moveRight();
	void rotate();
};
