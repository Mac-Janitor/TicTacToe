#ifndef GRID_H
#define GRID_H
#pragma once

#include "Sprite.hpp"

#include <vector>
	
class Grid  
{
	private:
		struct Item
		{
			Sprite* sprite;
			Rectangle box;
		};

		int m_columnCount;
		int m_rowCount;
		int m_spriteWidth;
		int m_spriteHeight;
		std::vector<std::vector<Item>> m_items;

	public:
		Grid();
		Grid(int screenWidth, int screenHeight, int columnCount, int rowCount);
		~Grid();

		void SetGridItem(int x, int y, Sprite* spr);
		void Draw();
		
		bool CheckItems(Vector2 mousePosition, Sprite* spr);
};
#endif