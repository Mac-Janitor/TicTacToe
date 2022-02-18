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

		public:

			UI(std::string label, float fontSize);
			~UI();

			void Draw(Vector2 position);
			Vector2 GetTextSize();

	};
}
#endif