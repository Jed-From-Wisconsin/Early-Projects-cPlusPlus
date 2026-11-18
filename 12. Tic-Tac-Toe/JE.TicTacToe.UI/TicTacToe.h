#pragma once
#include "Game.h"

class TicTacToe : public Game
{
public:
	TicTacToe();
	virtual ~TicTacToe();

	bool IsGameOver() const override;
	void TakeTurn() override;
	void Display() const override;

private:
	char m_board[9];
	char m_currentPlayer;
	char CheckWinAndDraw() const;
	void DisplayResult() const;
};