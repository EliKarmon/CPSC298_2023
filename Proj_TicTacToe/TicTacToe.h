#if !defined(TICTACTOE_H)
#define TICTACTOE_H
/// @file TicTacToe.cpp
///@brief header for tic tac toe class
///@author karmon@chapman.edu

#include <iostream>

class TicTacToe
{
    static const int k_dimensions = 3;
    bool gameOver;

    private:
        char** tttGrid;
        void createGrid();
        int m_rows;
        int m_columns;
        void takeTurn(); //decision-making AI takes a turn
        void playerClaim(int x, int y); //player chooses their square
        void printGrid(); //print the game
        void computerTurn(); //computer takes their turn
        bool checkForEnd(); //returns true if the player has won, the AI has one, or all squares are full
        bool checkIsValid(int y, int x);

    public:
        TicTacToe(); //creates new tic tac toe game object
        void play(); //holds game loop
        

};



#endif