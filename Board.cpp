#include "Board.h"
#include<iostream>
#include<stdexcept>

Board::Board()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;

    gameBoard = new int* [numRows];

    for (int i = 0; i < numRows; i++)
    {
        gameBoard[i] = new int[numCols];

        for (int j = 0; j < numCols; j++)
        {
            gameBoard[i][j] = 0;
        }
    }
}

void Board::printTab()
{
    for (int i = 0; i < numRows; i++)
    {
        std::cout << std::endl;

        for (int j = 0; j < numCols; j++)
        {
            std::cout << gameBoard[i][j] << " ";
        }
    }
}

Board::~Board()
{
    for (int i = 0; i < numRows; i++)
    {
        delete[] gameBoard[i];
    }

    delete[] gameBoard;
}
void Board::setCell(int row, int col, int value)
{   
     if (row >= 0 && row < numRows)
           {
                if (col >= 0 && col < numCols)
                    gameBoard[row][col] = value;
            }
            
    
}
int Board::getCell(int row, int col)
{
  
    if (row >= 0 && row < numRows)
    {
        if (col >= 0 && col < numCols)
            return gameBoard[row][col];
    }
    return 0;
}
bool Board::isRowFull(int row)
{
    if (row >= 0 && row < numRows)
    {
        for (int i = 0; i < numCols; i++)
        {
            if (gameBoard[row][i] == 0)
            {

                return false;
            }
        }
        return true;
    }
    return false;
}
void Board::placePiece(const Tetromino& piece)
{
    const int(&tab)[4][4] = piece.getTab();
    int x = piece.getX();
    int y = piece.getY();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tab[i][j] == 1)
                gameBoard[y + i][x + j] = 1;
        }
    }
}
void Board::delPiece(const Tetromino& piece)
{
    const int(&tab)[4][4] = piece.getTab();
    int x = piece.getX();
    int y = piece.getY();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tab[i][j] == 1)
            {
                gameBoard[y + i][x + j] = 0;
            }
        }
    }
}

void Board::clearBoard()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            gameBoard[i][j] = 0;
        }
    }
}
bool Board::canMove(const Tetromino& piece, int dx, int dy)
{
    int x = piece.getX();
    int y = piece.getY();
    int newCol, newRow;
    const int (&tab)[4][4] = piece.getTab();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0;j < 4;j++)
        {
            if (tab[i][j] == 1)
            {
                newRow = y + i + dy;
                newCol = x + j + dx;
                if (newRow < 0)
                    return false;
                if (newRow >= numRows)
                    return false;
                if (newCol < 0)
                    return false;
                if (newCol >= numCols)
                    return false;
                if (gameBoard[newRow][newCol] == 1)
                    return false;
            }
            

        }
    }
    return true;

}
bool Board::canRotate(const Tetromino& piece)
{
    int x = piece.getX();
    int y = piece.getY();
    const int (&tab)[4][4] = piece.getTab();
    int newCol, newRow;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0;j < 4;j++)
        {
            if (tab[i][j] == 1)
            {
                newRow = y + j;
                newCol = x + (3-i);
                if (newRow < 0)
                    return false;
                if (newRow >= numRows)
                    return false;
                if (newCol < 0)
                    return false;
                if (newCol >= numCols)
                    return false;
                if (gameBoard[newRow][newCol] == 1)
                    return false;
            }

        }
    }
    return true;
}
void Board::removeRow(int row)
{
    for (int i = row; i > 0; i--)
    {
        for (int j = 0; j < numCols; j++)
        {
            gameBoard[i][j] = gameBoard[i - 1][j];
        }
    }

    for (int j = 0; j < numCols; j++)
    {
        gameBoard[0][j] = 0;
    }
}
int Board::clearFullRows()
{
    int clearedRows = 0;
    int row = numRows - 1;
    while (row >= 0)
    {
        if (isRowFull(row))
        {
            removeRow(row);
            clearedRows++;
        }
        else
            row--;
    }
    return clearedRows;
}

int Board::getPixelWidth() const
{
    return numCols * cellSize;
}

int Board::getPixelHeight() const
{
    return numRows * cellSize;
}

void Board::draw(sf::RenderWindow& window) const
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            sf::RectangleShape cell({ static_cast<float>(cellSize), static_cast<float>(cellSize) });
            cell.setPosition({ static_cast<float>(j * cellSize), static_cast<float>(i * cellSize) });
            cell.setOutlineThickness(-1.f);
            cell.setOutlineColor(sf::Color(40, 40, 60));

            if (gameBoard[i][j] != 0)
                cell.setFillColor(sf::Color(0, 200, 220));
            else
                cell.setFillColor(sf::Color(18, 18, 28));

            window.draw(cell);
        }
    }
}
