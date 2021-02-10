
#pragma once

namespace Fotis
{
    namespace GraphicsUtility  
    {
        float GetFPS(float deltaTime);
        float GetShrinkPercentageOvertime(float& frameSize, float size, float fps, float time);
        struct Position
        {
            int x;
            int y;
        };
    };
}