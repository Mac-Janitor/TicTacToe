#include <list>

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_RICONS
#include "raygui/raygui.h"

#undef RAYGUI_IMPLEMENTATION  

#include "Fotis/Sprite.hpp"
#include "Fotis/Grid.hpp"

#include "TicTacToeGrid.hpp"

#define GLSL_VERSION            330
#define SUPPORT_BUSY_WAIT_LOOP

int main(void)
{
    const int screenWidth = 2048 * 0.35;
    const int screenHeight = 2048 * 0.35;

    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");

    TicTacToeGrid grid(screenWidth, screenHeight, 3, 3, "resources/sprBoard.png");
    Fotis::Sprite x("resources/sprX.png");
    Fotis::Sprite o("resources/sprO.png");

    bool xPiece = true;

    Vector2 mousePosition;

    // Load shader and setup location points and values
    Shader shader = LoadShader(0, FormatText("resources/shaders/glsl%i/blur_darken.fs", GLSL_VERSION));

    // Fontsize is used to when loading the font to create the texture atlas
    // Without loading the font with the fontsize the text is likely to look blurry when scaled to large sizes 
    int fontSize = 256;
    Font font = LoadFontEx("resources/fonts/NorthernLights.ttf", fontSize, 0, 256);

    GuiLoadStyleDefault();
    GuiSetFont(font);
    std::string fontMessage = "Tic Tac Toe";
    Rectangle textBounds = { 0, 0, 0, 0 };

    GuiSetStyle(DEFAULT, TEXT_SIZE, fontSize);

    int fontSpacing = GuiGetStyle(DEFAULT, TEXT_SPACING);

    textBounds.width = (int)MeasureTextEx(guiFont, fontMessage.c_str(), fontSize, fontSpacing).x;
    textBounds.height = (int)MeasureTextEx(guiFont, fontMessage.c_str(), fontSize, fontSpacing).y;
    textBounds.x = screenWidth/2 - textBounds.width / 2;
    textBounds.y = screenHeight/3.5;

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

        std::vector<Fotis::Cell> line = grid.CheckWinner();
        bool catsGame = false;
        if (line.size() != 3)
            catsGame = grid.CheckCatsGame();
        

        // Render
        BeginDrawing();

            // float deltaTime = GetFrameTime();

            BeginShaderMode(shader);
                ClearBackground(RAYWHITE);
                grid.Draw();
            EndShaderMode();

            if (line.size() == 3)
            {
                float startX = line.front().box.width / 2 +  line.front().box.x;
                float startY = line.front().box.height / 2 + line.front().box.y;
                float endX = line.back().box.width / 2 + line.back().box.x;
                float endY = line.back().box.height / 2 + line.back().box.y;

                Vector2 startPos = {startX, startY};
                Vector2 endPos = {endX, endY};

                DrawLineEx(startPos, endPos, 5.0f, BLACK);
            }

            if (catsGame)
            {
                Vector2 start = { screenWidth / 3 * 2, screenHeight / 3 };
                Vector2 middle = { 0, screenHeight / 2 };
                Vector2 end = { screenWidth / 3 * 2, screenHeight / 3 * 2 };
                Fotis::GraphicsUtility::DrawLineBezierQuad(start, end, middle, 5.0f, RED);
            }

            GuiLabel(textBounds, fontMessage.c_str());

        EndDrawing();
    }

    CloseWindow();                // Close window and OpenGL context

    return 0;
}