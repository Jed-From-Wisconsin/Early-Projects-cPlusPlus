#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe()
{
    //Initialize the board with empty spaces
    for (int i = 0; i < 9; i++) 
    {
        m_board[i] = ' ';
    }
    
    //Always start with player X
    m_currentPlayer = 'X';
}

TicTacToe::~TicTacToe() {}

bool TicTacToe::IsGameOver() const
{
    return CheckWinAndDraw() != ' '; //If the result is not an empty space, the game is over
}

void TicTacToe::Display() const
{
    for (int i = 0; i < 9; i++)
    {
        if (m_board[i] == ' ') //If the space is blank
            std::cout << (i + 1); //Assign a number to it
        else
            std::cout << m_board[i]; //Otherwise, display the letter in the space

        if (i==2 || i==5 || i==8) //If we are at the end of a row
        {
            std::cout << "\n"; //Go to the next line
        }
        else
        {
            std::cout << " | "; //Otherwise, put a divider between spaces
        }
    }
}

void TicTacToe::TakeTurn()
{
    //Define variables
    int move;
    bool validMove = false;

    while (validMove == false) //As long as validMove has the false value, do this
    {
        //Prompt player to put in their move
        std::cout << "Player " << m_currentPlayer << ", enter position (1-9): ";
        std::cin >> move;

        int moveOffset = move - 1; //Account for offset

        if (moveOffset >= 0 && moveOffset < 9 && m_board[moveOffset] == ' ') //If everything has been input correctly
        {
            m_board[moveOffset] = m_currentPlayer; //Change board place to the letter of current player
            validMove = true; //Set validMove to true, breaking the loop
        }
        else //if it is not right
        {
            std::cout << "Invalid move. Put in another.\n"; 
        }

        if (CheckWinAndDraw() != ' ') //If a char is returned
        {
            DisplayResult();
        }
    }

    //If it is X's turn, change to O
    //If it is not X's turn, change to X's turn
    if (m_currentPlayer == 'X') 
    {
        m_currentPlayer = 'O';
    }
    else
    {
        m_currentPlayer = 'X';
    }
}

char TicTacToe::CheckWinAndDraw() const
{
    //ugh

    //Check Rows
    if (m_board[0] != ' ' && m_board[0] == m_board[1] && m_board[1] == m_board[2]) //If these spaces are not blank, and have the same letter in them
        return m_board[0]; //Return the letter in that space
    if (m_board[3] != ' ' && m_board[3] == m_board[4] && m_board[4] == m_board[5])
        return m_board[3];
    if (m_board[6] != ' ' && m_board[6] == m_board[7] && m_board[7] == m_board[8])
        return m_board[6];

    //Check columns
    if (m_board[0] != ' ' && m_board[0] == m_board[3] && m_board[3] == m_board[6])
        return m_board[0];
    if (m_board[1] != ' ' && m_board[1] == m_board[4] && m_board[4] == m_board[7])
        return m_board[1];
    if (m_board[2] != ' ' && m_board[2] == m_board[5] && m_board[5] == m_board[8])
        return m_board[2];

    //Check diagonals
    if (m_board[0] != ' ' && m_board[0] == m_board[4] && m_board[4] == m_board[8])
        return m_board[0];
    if (m_board[2] != ' ' && m_board[2] == m_board[4] && m_board[4] == m_board[6])
        return m_board[2];

    // Check for ongoing game
    for (int i = 0; i < 9; i++)
    {
        if (m_board[i] == ' ') //If there is an empty space, return a blank character
            return ' ';
    }

    //If there is no winner, but no moves left, return a draw
    return 'D';
}

void TicTacToe::DisplayResult() const
{
    char result = CheckWinAndDraw(); //Take character from CheckWinAndDraw
    if (result == 'X' || result == 'O')
    {
        std::cout << "Player " << result << " is victorious.\n";
    }
    else if (result == 'D')
    {
        std::cout << "Neither side wins, neither side loses.\n";
        std::cout << "It is as it was.\n";
    }
}