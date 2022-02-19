#ifndef UI_H
#define UI_H
#pragma once
	
#include "raylib.h"

#include <iostream>

#define GLSL_VERSION            330

namespace Fotis
{
	class UI  
	{
		private:
			Font m_font;
			std::string m_label;
			float m_fontSize;
			Vector2 m_position;
			Vector2 m_textSize;

		public:

			UI(std::string label, float fontSize, Vector2 centerOriginPosition);
			~UI();

			void Draw(Color color);

			bool Hover(Vector2 mousePosition);
	};
}
#endif