#ifndef CELL_H
#define CELL_H
#pragma once
	
#include "Sprite.hpp"

namespace Fotis
{
	class Cell  
	{
		public:
			Sprite* sprite;
			Rectangle box;

		friend bool operator!= (const Cell &c1, const Cell &c2);
		friend bool operator== (const Cell &c1, const Cell &c2);
			
	};


    // bool operator!= (const Cell &c1, const Cell &c2)
    // {
    //     return (c1.sprite != c2.sprite);
    // }	
}

#endif