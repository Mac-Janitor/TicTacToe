#include "TicTacToeGrid.hpp"  
#include "Fotis/Cell.hpp"

TicTacToeGrid::TicTacToeGrid() : Fotis::Grid()
{
	
}

TicTacToeGrid::TicTacToeGrid (int screenWidth, int screenHeight, int columnCount, int rowCount, std::string backgroundImagePath)
     : Fotis::Grid (screenWidth, screenHeight, columnCount, rowCount, backgroundImagePath) {}
	
TicTacToeGrid::~TicTacToeGrid()
{
	
}

std::vector<Fotis::Cell> TicTacToeGrid::CheckWinner()
{
    // Check Rows
    for (int i = 0; i < m_rowCount; i++)
    {
        std::vector<Fotis::Cell> row = GetRow(i);
        int columnMatchCount = 0;

        for (Fotis::Cell cell : row)
        {
            if (cell.sprite != NULL && cell == row.front())
            {
                columnMatchCount++;
            }
        }

        if (columnMatchCount == m_columnCount)
        {
            return row;
        }
    }

    // Check Columns
    for (int i = 0; i < m_columnCount; i++)
    {
        std::vector<Fotis::Cell> column = GetColumn(i);
        int rowMatchCount = 0;

        for (Fotis::Cell cell : column)
        {
            if (cell.sprite != NULL && cell == column.front())
            {
                rowMatchCount++;
            }
        }

        if (rowMatchCount == m_rowCount)
        {
            return column;
        }
    }

    std::vector<Fotis::Cell> diagonal;
    // Check Diagonals
    for (int i = 0; i < m_columnCount; i++)
    {
        diagonal.push_back(m_items[i][i]);
    }
    int diagonalCount = 0;

    for (Fotis::Cell cell : diagonal)
    {
        if (cell.sprite != NULL && cell == diagonal.front())
        {
            diagonalCount++;
        }
    }

    if (diagonalCount == m_rowCount)
    {
        return diagonal;
    }

    diagonal.clear();
    diagonalCount = 0;
    int x = 0;
    for (int y = m_columnCount - 1; y >= 0; y--)
    {
        diagonal.push_back(m_items[x][y]);
        x++;
    }

    for (Fotis::Cell cell : diagonal)
    {
        if (cell.sprite != NULL && cell == diagonal.front())
        {
            diagonalCount++;
        }
    }

    if (diagonalCount == m_rowCount)
    {
        return diagonal;
    }

    // Check Cats Game
    for (int x = 0; x < m_rowCount; x++)
    {
        for (int y = 0; y < m_columnCount; y++)
        {
            
        }
    }

    return std::vector<Fotis::Cell> {};
}