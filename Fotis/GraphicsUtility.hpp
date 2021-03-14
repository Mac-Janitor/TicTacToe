
#pragma once

#include <math.h>

#include "raylib.h"

namespace Fotis
{
    namespace GraphicsUtility  
    {
        float GetFPS(float deltaTime);
        float GetShrinkPercentageOvertime(float& frameSize, float size, float fps, float time);
        float EaseCubicIn(float t, float b, float c, float d);
        float EaseCubicOut(float t, float b, float c, float d);
        float EaseCubicInOut(float t, float b, float c, float d);
        void DrawLineBezierQuad(Vector2 startPos, Vector2 endPos, Vector2 controlPos, float thick, Color color);
        struct Position
        {
            int x;
            int y;
        };
    };
}