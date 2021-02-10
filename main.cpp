#include <list>

#include "raylib.h"

#include "Fotis/Sprite.hpp"
#include "Fotis/Grid.hpp"

int main(void)
{
    const int screenWidth = 2048 * 0.35;
    const int screenHeight = 2048 * 0.35;

    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");

    Fotis::Grid grid(screenWidth, screenHeight, 3, 3, "resources/sprBoard.png");
    Fotis::Sprite x("resources/sprX.png");
    Fotis::Sprite o("resources/sprO.png");

    bool xPiece = true;

    Vector2 mousePosition;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        mousePosition = {-1, -1};
        // Input
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            mousePosition = GetMousePosition();

        // Update
        if (xPiece)
        {
            if (grid.CheckItems(mousePosition, &x))
                xPiece = !xPiece;
        }
        else
        {
            if (grid.CheckItems(mousePosition, &o))
                xPiece = !xPiece;
        }
        

        // Render
        BeginDrawing();

            ClearBackground(RAYWHITE);

            float deltaTime = GetFrameTime();

            grid.Draw();

        EndDrawing();
    }

    CloseWindow();                // Close window and OpenGL context

    return 0;
}