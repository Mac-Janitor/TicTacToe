#include "Grid.hpp"  
	
using namespace Fotis;

Grid::Grid()
{
	
}

Grid::Grid(int screenWidth, int screenHeight, int columnCount, int rowCount, std::string backgroundImagePath)
{
    backgroundSpr = new Sprite(backgroundImagePath);
    m_columnCount = columnCount;
    m_rowCount = rowCount;
    m_spriteWidth = screenWidth / m_columnCount;
    m_spriteHeight = screenHeight / m_rowCount;


    for (int i = 0; i < m_columnCount; i++)
    {
        std::vector<Cell> columnItems;
        for (int j = 0; j < m_rowCount; j++)
        {
            int x = m_spriteWidth * i;
            int y = m_spriteHeight * j;
            Cell item = {NULL, (float)x, (float)y, (float)m_spriteWidth, (float)m_spriteHeight};
            columnItems.push_back(item);
        }
        m_items.push_back(columnItems);
    } 
}
	
Grid::~Grid()
{
	delete backgroundSpr;
}

void Grid::SetGridItem(int x, int y, Sprite* spr)
{
    m_items[x][y].sprite = spr;
}

void Grid::Draw()
{
    if (backgroundSpr != NULL)
        backgroundSpr->Draw(0, 0);
        
    for (int i = 0; i < m_columnCount; i++)
    {
        for (int j = 0; j < m_rowCount; j++)
        {
            // Draw in the middle of the box
            Sprite* spr = m_items[i][j].sprite;
            if (spr != NULL)
            {
                int posX = (m_spriteWidth * i) + ((m_spriteWidth - spr->GetWidth()) / 2);
                int posY = (m_spriteHeight * j) + ((m_spriteHeight - spr->GetHeight()) / 2);
                spr->Draw(posX, posY);
            }
        }
    }
}

bool Grid::CheckItems(Vector2 mousePosition, Sprite* spr)
{
    if (mousePosition.x >= 0 && mousePosition.y >= 0)
    {
        for (int i = 0; i < m_columnCount; i++)
        {
            for (int j = 0; j < m_rowCount; j++)
            {
                if (mousePosition.x > m_items[i][j].box.x 
                && mousePosition.x <= m_items[i][j].box.width + m_items[i][j].box.x 
                && mousePosition.y > m_items[i][j].box.y
                && mousePosition.y <= m_items[i][j].box.height + m_items[i][j].box.y)
                {
                    if (m_items[i][j].sprite == NULL)
                    {
                        SetGridItem(i, j, spr);
                        return true;
                    }
                }
            }        
        }
    }

    return false;
}