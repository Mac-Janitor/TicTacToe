#include "Grid.hpp"  
	
Grid::Grid()
{
	
}

Grid::Grid(int screenWidth, int screenHeight, int columnCount, int rowCount)
{
    m_columnCount = columnCount;
    m_rowCount = rowCount;
    m_spriteWidth = screenWidth / m_columnCount;
    m_spriteHeight = screenHeight / m_rowCount;

    m_sprites = std::vector<std::vector<Sprite*>> (columnCount, std::vector<Sprite*>(rowCount, NULL));
    for (int i = 0; i < m_columnCount; i++)
    {
        std::vector<Rectangle> columnItems;
        for (int j = 0; j < m_rowCount; j++)
        {
            int x = m_spriteWidth * i;
            int y = m_spriteHeight * j;
            columnItems.push_back({(float)x, (float)y, (float)m_spriteWidth, (float)m_spriteHeight});
        }
        m_items.push_back(columnItems);
    } 
}
	
Grid::~Grid()
{
	
}

void Grid::SetGridItem(int x, int y, Sprite* spr)
{
    m_sprites[x][y] = spr;
}

void Grid::Draw()
{
    for (int i = 0; i < m_columnCount; i++)
    {
        for (int j = 0; j < m_rowCount; j++)
        {
            // Draw in the middle of the box
            Sprite* spr = m_sprites[i][j];
            if (spr != NULL)
            {
                int posX = (m_spriteWidth * i) + ((m_spriteWidth - spr->GetWidth()) / 2);
                int posY = (m_spriteHeight * j) + ((m_spriteHeight - spr->GetHeight()) / 2);
                spr->Draw(posX, posY);
            }
        }
    }
}

void Grid::CheckItems(Vector2 mousePosition, Sprite* spr)
{
    if (mousePosition.x >= 0 && mousePosition.y >= 0)
    {
        for (int i = 0; i < m_columnCount; i++)
        {
            for (int j = 0; j < m_rowCount; j++)
            {
                if (mousePosition.x > m_items[i][j].x 
                && mousePosition.x <= m_items[i][j].width + m_items[i][j].x 
                && mousePosition.y > m_items[i][j].y
                && mousePosition.y <= m_items[i][j].height + m_items[i][j].y)
                {
                    SetGridItem(i, j, spr);
                }
            }        
        }
    }
}