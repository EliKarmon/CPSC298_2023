#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include "TicTacToe.h"

TicTacToe::TicTacToe() : m_rows(k_dimensions), m_columns(k_dimensions)
{
    createGrid();
}
void TicTacToe::createGrid()
{
    tttGrid = new char* [m_columns];
    for(int i = 0; i < m_rows; i++)
    {
        tttGrid[i] = new char[m_columns];
    }

    for(int i = 0; i < m_rows; i++)
    {
        for(int j = 0; j < m_columns; j++)
        {
            tttGrid[i][j] = '~';
        }
    }
}
void TicTacToe::play()
{
    int columnInput;
    int rowInput;
    while(!checkForEnd())
    {
        printGrid();
        std::cout<<"Enter row for your move: ";
        std::cin >> rowInput;
        std::cout << "Enter column for your move: ";
        std:: cin >> columnInput; 
        if(!checkIsValid(rowInput,columnInput)) //restarts while loop if there is invalid input
        {
            std::cout << "please enter values from 0 to 2 that are not already occupied" << std::endl;
            continue;
        }
        else
        {
            tttGrid[rowInput][columnInput] = 'X';
        }
        computerTurn();
    }  
    std::cout << "GAME OVER!" << std::endl;
    printGrid();
    delete[] tttGrid;
}
void TicTacToe::printGrid()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout << tttGrid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void TicTacToe::computerTurn()
{
    bool breaking = false;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(checkIsValid(i,j))
            {
                tttGrid[i][j] = 'O';
                breaking = true;
                break;
            }
        }
        if(breaking)
        {
            break;
        }
    }
}
bool TicTacToe::checkIsValid(int y, int x)
{
    if(y > 2 || x > 2)
    {
        return false;
    }
    if(tttGrid[y][x] != '~')
    {
        return false;
    }
    return true;
}
bool TicTacToe::checkForEnd()
{
    //checks for vertical column victory
    for(int topCol = 0; topCol < 3; topCol++)
    {
        if(tttGrid[0][topCol] != '~' && tttGrid[1][topCol] == tttGrid[0][topCol] && tttGrid[2][topCol] == tttGrid[0][topCol])
        {
            return true;
        }
    }
    //check for horizontal row victory
    for(int firstRow = 0; firstRow < 3; firstRow++)
    {
        if(tttGrid[firstRow][0] != '~' && tttGrid[firstRow][1] == tttGrid[firstRow][0] && tttGrid[firstRow][2] == tttGrid[firstRow][0])
        {
            return true;
        }
    }
    //check for diagonal victory
    if(tttGrid[0][0] != '~' && tttGrid[1][1] == tttGrid[0][0] && tttGrid[2][2] == tttGrid[0][0])
        {
            return true;
        }
     if(tttGrid[0][2] != '~' && tttGrid[1][1] == tttGrid[0][2] && tttGrid[2][0] == tttGrid[0][2])
        {
            return true;
        }
    //check for tie
    bool allFilled = true;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(tttGrid[i][j] == '~')
            {
                allFilled = false;
            }
        }
    }
    if(allFilled)
    {
        return true;
    }
    return false;
}