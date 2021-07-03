#include "Cell.hpp"  
	

namespace Fotis
{
    bool operator!= (const Cell &c1, const Cell &c2)
    {
        return c1.sprite != c2.sprite;
    }

    bool operator== (const Cell &c1, const Cell &c2)
    {
        return c1.sprite == c2.sprite;
    }    
}