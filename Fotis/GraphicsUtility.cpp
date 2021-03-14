#include "GraphicsUtility.hpp"


namespace Fotis
{
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

        // Cubic Easing functions
        float EaseCubicIn(float t, float b, float c, float d) { t /= d; return (c*t*t*t + b); }
        float EaseCubicOut(float t, float b, float c, float d) { t = t/d - 1.0f; return (c*(t*t*t + 1.0f) + b); }
        float EaseCubicInOut(float t, float b, float c, float d)
        {
            if ((t/=d/2.0f) < 1.0f) return (c/2.0f*t*t*t + b);
            t -= 2.0f; return (c/2.0f*(t*t*t + 2.0f) + b);
        }

        // Draw line using quadratic bezier curves with a control point
        void DrawLineBezierQuad(Vector2 startPos, Vector2 endPos, Vector2 controlPos, float thick, Color color)
        {
            const float step = 1.0f/24;
            
            Vector2 previous = startPos;
            Vector2 current = { 0 };
            float t = 0.0f;
            
            for (int i = 0; i <= 24; i++)
            {
                t = step*i;
                float a = powf(1 - t, 2);
                float b = 2*(1 - t)*t;
                float c = powf(t, 2);
                
                // NOTE: The easing functions aren't suitable here because they don't take a control point
                current.y = a*startPos.y + b*controlPos.y + c*endPos.y;
                current.x = a*startPos.x + b*controlPos.x + c*endPos.x;
                
                DrawLineEx(previous,current,thick,color);
                
                previous = current;
            }
        }        
    }
}