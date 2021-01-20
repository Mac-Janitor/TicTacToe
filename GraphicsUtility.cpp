#include "GraphicsUtility.hpp"  

namespace GraphicsUtility
{
	float GetFPS(float deltaTime)
    {
        return 1.0 / deltaTime;
    }

	float GetShrinkPercentageOvertime(float& frameSize, float size, float fps, float time)
    {
        frameSize -= size * (1 / (fps * time));
        return frameSize / size;
    }


}