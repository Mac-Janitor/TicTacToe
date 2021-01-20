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
    // grid.SetGridItem(0, 0, &x);
    // grid.SetGridItem(0, 1, &x);
    // grid.SetGridItem(0, 2, &x);
    // grid.SetGridItem(1, 0, &o);
    // grid.SetGridItem(1, 1, &o);
    // grid.SetGridItem(1, 2, &o);

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
        // if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
        //     present.MoveLeft();
        // if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
        //     present.MoveRight();   
        // if (IsKeyPressed(KEY_SPACE)) 
        //     present.DropGift();

        // Update
        grid.CheckItems(mousePosition, &x);

        // Render
        BeginDrawing();

            ClearBackground(RAYWHITE);

            float deltaTime = GetFrameTime();

            for (Sprite* spr : resourceList) 
            {
                spr->Draw(0, 0);
            }
            
            grid.Draw();
            // x.Draw((int)grid.items[0][1].x, (int)grid.items[0][1].y);

        EndDrawing();
    }

    CloseWindow();                // Close window and OpenGL context

    return 0;
}