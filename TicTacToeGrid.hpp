#ifndef TICTACTOEGRID_H
#define TICTACTOEGRID_H
#pragma once

#include "Fotis/Grid.hpp"
	
class TicTacToeGrid : public Fotis::Grid
{
	private:

	public:

		TicTacToeGrid();
		TicTacToeGrid (int screenWidth, int screenHeight, int columnCount, int rowCount, std::string backgroundImagePath);
		~TicTacToeGrid();

		std::vector<Fotis::Cell> CheckWinner();
};
#endif