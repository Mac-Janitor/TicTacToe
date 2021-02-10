#ifndef CELL_H
#define CELL_H
#pragma once
	
#include "Sprite.hpp"

namespace Fotis
{
	struct Cell  
	{
		Sprite* sprite;
		Rectangle box;
	};
}

#endif