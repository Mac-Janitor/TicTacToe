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
    int count = 0;

    // Check Rows
    for (int i = 0; i < m_rowCount; i++)
    {
        count = 0;
        std::vector<Fotis::Cell> row = GetRow(i);

        for (Fotis::Cell cell : row)
        {
            if (cell.sprite != NULL && cell == row.front())
            {
                count++;
            }
        }

        if (count == m_columnCount)
        {
            return row;
        }
    }

    // Check Columns
    for (int i = 0; i < m_columnCount; i++)
    {
        count = 0;
        std::vector<Fotis::Cell> column = GetColumn(i);

        for (Fotis::Cell cell : column)
        {
            if (cell.sprite != NULL && cell == column.front())
            {
                count++;
            }
        }

        if (count == m_rowCount)
        {
            return column;
        }
    }

    std::vector<Fotis::Cell> diagonal;
    count = 0;
    // Check Diagonals
    for (int i = 0; i < m_columnCount; i++)
    {
        diagonal.push_back(m_items[i][i]);
    }

    for (Fotis::Cell cell : diagonal)
    {
        if (cell.sprite != NULL && cell == diagonal.front())
        {
            count++;
        }
    }

    if (count == m_rowCount)
    {
        return diagonal;
    }

    diagonal.clear();
    count = 0;
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
            count++;
        }
    }

    if (count == m_rowCount)
    {
        return diagonal;
    }

    return std::vector<Fotis::Cell> {};
}

bool TicTacToeGrid::CheckCatsGame()
{
    int count = 0;
    // Check Cats Game
    for (int x = 0; x < m_rowCount; x++)
    {
        for (int y = 0; y < m_columnCount; y++)
        {
            if (m_items[x][y].sprite != NULL)
            {
                count++;
            }
        }
    }

    if (count == m_rowCount * m_columnCount)
    {
        return true;
    }  

    return false;  
}