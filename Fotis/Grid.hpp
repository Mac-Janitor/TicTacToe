#ifndef GRID_H
#define GRID_H
#pragma once

#include "Sprite.hpp"
#include "Cell.hpp"

#include <vector>

namespace Fotis
{
	class Grid  
	{
		protected:
			int m_columnCount;
			int m_rowCount;
			int m_spriteWidth;
			int m_spriteHeight;
			std::vector<std::vector<Cell>> m_items;
			Sprite* backgroundSpr;

			std::vector<Cell> GetRow(int index);
			std::vector<Cell> GetColumn(int index);

		public:
			Grid();
			Grid(int screenWidth, int screenHeight, int columnCount, int rowCount, std::string backgroundPath);
			~Grid();

			void SetGridItem(int x, int y, Sprite* spr);
			void Draw();

			void Reset();
			
			bool CheckItems(Vector2 mousePosition, Sprite* spr);
	};
}

#endif