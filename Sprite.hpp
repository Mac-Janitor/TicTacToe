
#pragma once

#include "raylib.h"
#include "string"
#include "GraphicsUtility.hpp"

#include <iostream>

class Sprite  
{
	private:
		bool m_empty;

		int m_width;
		int m_height;

		GraphicsUtility::Position m_position;

	public:
		Sprite();
		Sprite (std::string imagePath);
		~Sprite();

		Image image;
		Texture texture;

		void Draw();
		void Draw(int posX, int posY);
		int GetWidth();
		int GetHeight();
};