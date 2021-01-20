#include <list>

#include "raylib.h"

#include "Sprite.hpp"
#include "Grid.hpp"

int main(void)
{
    const int screenWidth = 2048 * 0.35;
    const int screenHeight = 2048 * 0.35;

    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");

    Sprite board("resources/sprBoard.png");
    Grid grid(screenWidth, screenHeight, 3, 3);
    Sprite x("resources/sprX.png");
    Sprite o("resources/sprO.png");

    bool xPiece = true;

    Vector2 mousePosition;

    std::list<Sprite*> resourceList
    {
        &board
    };

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

            for (Sprite* spr : resourceList) 
            {
                spr->Draw(0, 0);
            }
            
            grid.Draw();

        EndDrawing();
    }

    CloseWindow();                // Close window and OpenGL context

    return 0;
}