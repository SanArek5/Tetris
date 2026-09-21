#include "Tetromino.h"
#include<iostream>
int Tetromino::getX() const { return x; }
int Tetromino::getY() const { return y; }
const int(&Tetromino::getTab() const)[4][4]
{
    return PieceTab;
}
Tetromino::Tetromino(PieceType type)
{
	this->type = type;
    x = 3;
    y = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0 ;j < 4; j++)
            PieceTab[i][j] = 0;
    }
    switch (type)
    {
    case PieceType::O:
        PieceTab[1][1] = 1;
        PieceTab[1][2] = 1;
        PieceTab[2][1] = 1;
        PieceTab[2][2] = 1;
        break;

    case PieceType::L:
        PieceTab[0][1] = 1;
        PieceTab[1][1] = 1;
        PieceTab[2][1] = 1;
        PieceTab[2][2] = 1;
        break;

    case PieceType::J:
        PieceTab[0][1] = 1;
        PieceTab[1][1] = 1;
        PieceTab[2][1] = 1;
        PieceTab[2][0] = 1;
        break;

    case PieceType::Z:
        PieceTab[0][0] = 1;
        PieceTab[0][1] = 1;
        PieceTab[1][1] = 1;
        PieceTab[1][2] = 1;
        break;

    case PieceType::S:
        PieceTab[0][1] = 1;
        PieceTab[0][2] = 1;
        PieceTab[1][0] = 1;
        PieceTab[1][1] = 1;
        break;

    case PieceType::I:
        PieceTab[1][0] = 1;
        PieceTab[1][1] = 1;
        PieceTab[1][2] = 1;
        PieceTab[1][3] = 1;
        break;

    case PieceType::T:
        PieceTab[0][1] = 1;
        PieceTab[1][0] = 1;
        PieceTab[1][1] = 1;
        PieceTab[1][2] = 1;
        break;
    }
}
void Tetromino::printPiece()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0;j < 4; j++)
        {
            std::cout << PieceTab[i][j];
        }
        std::cout << std::endl;
    }
    
}
void Tetromino::move(int xx, int yy)
{
    this->x += xx;
    this->y += yy;
}
void Tetromino::rotate()
{
    int temp[4][4];
    for (int i = 0;i < 4;i++)
    {
        for (int j = 0;j < 4;j++)
        {
            temp[j][3-i] = PieceTab[i][j];
        }
    }
    for (int i = 0;i < 4;i++)
    {
        for (int j = 0;j < 4;j++)
        {
            PieceTab[i][j] = temp[i][j];
        }
    }

}
