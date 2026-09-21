#include "Game.h"
#include <string>

namespace
{
const char* glyph(char character)
{
	switch (character)
	{
	case 'A': return "01110 10001 10001 11111 10001 10001 10001";
	case 'C': return "01111 10000 10000 10000 10000 10000 01111";
	case 'E': return "11111 10000 10000 11110 10000 10000 11111";
	case 'G': return "01111 10000 10000 10111 10001 10001 01111";
	case 'I': return "11111 00100 00100 00100 00100 00100 11111";
	case 'K': return "10001 10010 10100 11000 10100 10010 10001";
	case 'L': return "10000 10000 10000 10000 10000 10000 11111";
	case 'M': return "10001 11011 10101 10101 10001 10001 10001";
	case 'N': return "10001 11001 10101 10011 10001 10001 10001";
	case 'P': return "11110 10001 10001 11110 10000 10000 10000";
	case 'R': return "11110 10001 10001 11110 10100 10010 10001";
	case 'S': return "01111 10000 10000 01110 00001 00001 11110";
	case 'T': return "11111 00100 00100 00100 00100 00100 00100";
	case 'W': return "10001 10001 10001 10101 10101 10101 01010";
	case 'V': return "10001 10001 10001 10001 10001 01010 00100";
	case 'Y': return "10001 10001 01010 00100 00100 00100 00100";
	case '0': return "01110 10001 10011 10101 11001 10001 01110";
	case '1': return "00100 01100 00100 00100 00100 00100 01110";
	case '2': return "01110 10001 00001 00010 00100 01000 11111";
	case '3': return "11110 00001 00001 01110 00001 00001 11110";
	case '4': return "00010 00110 01010 10010 11111 00010 00010";
	case '5': return "11111 10000 10000 11110 00001 00001 11110";
	case '6': return "01110 10000 10000 11110 10001 10001 01110";
	case '7': return "11111 00001 00010 00100 01000 01000 01000";
	case '8': return "01110 10001 10001 01110 10001 10001 01110";
	case '9': return "01110 10001 10001 01111 00001 00001 01110";
	default: return "00000 00000 00000 00000 00000 00000 00000";
	}
}

void drawPixelText(sf::RenderWindow& window, const std::string& text, float x, float y, float scale, sf::Color color)
{
	for (std::size_t letter = 0; letter < text.size(); ++letter)
	{
		const char* pattern = glyph(text[letter]);
		for (int row = 0; row < 7; ++row)
		{
			for (int col = 0; col < 5; ++col)
			{
				if (pattern[row * 6 + col] == '0')
					continue;
				sf::RectangleShape pixel({ scale, scale });
				pixel.setPosition({ x + (letter * 6 + col) * scale, y + row * scale });
				pixel.setFillColor(color);
				window.draw(pixel);
			}
		}
	}
}
}

PieceType Game::getRandomPieceType()
{
	std::uniform_int_distribution<int> distribution(0, 6);

	int randomNumber = distribution(generator);

	return static_cast<PieceType>(randomNumber);

}
Game::Game() : currentPiece(PieceType::T), nextPieceType(PieceType::O), score(0), generator(std::random_device{}())
{
	gameover = false;
	nextPieceType = getRandomPieceType();
	board.placePiece(this->currentPiece);
}


void Game::print()
{
	board.printTab();
}
void Game::moveDown()
{
	if (gameover)
	{
		return;
	}

	board.delPiece(currentPiece);
	if (board.canMove(currentPiece, 0, 1))
	{
		currentPiece.move(0, 1);
		board.placePiece(currentPiece);
	}
	else
	{
		board.placePiece(currentPiece);
		const int clearedRows = board.clearFullRows();
		if (clearedRows > 0)
			score += static_cast<unsigned int>(clearedRows * clearedRows * 100);

		currentPiece = Tetromino(nextPieceType);
		nextPieceType = getRandomPieceType();
		if (board.canMove(currentPiece, 0, 0))
		{
			board.placePiece(currentPiece);
		}
		else
			gameover = true;
		
	}

}

void Game::moveLeft()
{
	if (gameover)
	{
		return;
	}

	board.delPiece(currentPiece);
	if (board.canMove(currentPiece, -1, 0))
	{
		currentPiece.move(-1, 0);
		board.placePiece(currentPiece);
	}
	else
	{
		board.placePiece(currentPiece);
	}
}
void Game::moveRight()
{
	if (gameover)
	{
		return;
	}

	board.delPiece(currentPiece);
	if (board.canMove(currentPiece, 1, 0))
	{
		currentPiece.move(1, 0);
		board.placePiece(currentPiece);
	}
	else
	{
		board.placePiece(currentPiece);
	}
}
void Game::rotate()
{
	if (gameover)
	{
		return;
	}

	board.delPiece(currentPiece);
	if (board.canRotate(currentPiece))
	{
		currentPiece.rotate();
		board.placePiece(currentPiece);
	}
	else
	{
		board.placePiece(currentPiece);
	}
}


bool Game::isGameOver() const { return gameover;}

void Game::resetGame()
{
	board.clearBoard();
	score = 0;
	gameover = false;
	currentPiece = Tetromino(getRandomPieceType());
	nextPieceType = getRandomPieceType();
	board.placePiece(currentPiece);
}

void Game::drawSidePanel(sf::RenderWindow& window) const
{
	const float panelX = static_cast<float>(board.getPixelWidth() + 20);
	const float cellSize = 22.f;
	drawPixelText(window, "NASTEPNY", panelX, 12.f, 2.f, sf::Color(255, 220, 100));
	drawPixelText(window, "KL0CEK", panelX + 12.f, 30.f, 2.f, sf::Color(255, 220, 100));

	
	Tetromino preview(nextPieceType);
	const int (&shape)[4][4] = preview.getTab();
	for (int row = 0; row < 4; ++row)
	{
		for (int col = 0; col < 4; ++col)
		{
			if (shape[row][col] == 0)
				continue;

			sf::RectangleShape block({ cellSize - 2.f, cellSize - 2.f });
			block.setPosition({ panelX + col * cellSize, 58.f + row * cellSize });
			block.setFillColor(sf::Color(255, 180, 50));
			block.setOutlineThickness(1.f);
			block.setOutlineColor(sf::Color(255, 230, 150));
			window.draw(block);
		}
	}

	drawPixelText(window, "WYNIK", panelX + 18.f, 170.f, 2.f, sf::Color(100, 230, 140));
	drawPixelText(window, std::to_string(score), panelX, 190.f, 3.f, sf::Color(100, 230, 140));
}

void Game::run()
{
	const unsigned int width = static_cast<unsigned int>(board.getPixelWidth() + 140);
	const unsigned int height = static_cast<unsigned int>(board.getPixelHeight());
	sf::RenderWindow window(sf::VideoMode({ width, height }), "Tetris");
	window.setFramerateLimit(60);

	sf::Clock gravityClock;
	const sf::Time gravityInterval = sf::milliseconds(400);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			else if (const auto* key = event->getIf<sf::Event::KeyPressed>())
			{
				if (key->code == sf::Keyboard::Key::Escape)
				{
					window.close();
				}
				else if (gameover && key->code == sf::Keyboard::Key::R)
				{
					resetGame();
					gravityClock.restart();
				}
				else if (!gameover)
				{
					if (key->code == sf::Keyboard::Key::Left)
						moveLeft();
					else if (key->code == sf::Keyboard::Key::Right)
						moveRight();
					else if (key->code == sf::Keyboard::Key::Up)
						rotate();
					else if (key->code == sf::Keyboard::Key::Down)
						moveDown();
				}
			}
		}

		if (!gameover && gravityClock.getElapsedTime() >= gravityInterval)
		{
			moveDown();
			gravityClock.restart();
		}

		window.clear(sf::Color(10, 10, 16));
		board.draw(window);
		drawSidePanel(window);
		if (gameover)
		{
			drawPixelText(window, "GAME 0VER", 82.f, 270.f, 4.f, sf::Color(255, 80, 80));
			drawPixelText(window, "R P0N0WNIE", 70.f, 310.f, 3.f, sf::Color(255, 220, 100));
		}
		window.display();
	}
}
