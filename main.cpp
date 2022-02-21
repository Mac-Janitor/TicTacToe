#include <list>

#include "raylib.h"

#include "Fotis/Sprite.hpp"
#include "Fotis/Grid.hpp"
#include "Fotis/UI.hpp"

#include "TicTacToeGrid.hpp"

#define GLSL_VERSION            330
#define SUPPORT_BUSY_WAIT_LOOP

int main(void)
{
    const int screenWidth = 2048 * 0.35;
    const int screenHeight = 2048 * 0.35;

    enum GAME_STATE
    {
        START_MENU,
        GAME_RUNNING,
        GAME_OVER   
    };

    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");

    TicTacToeGrid grid(screenWidth, screenHeight, 3, 3, "resources/sprBoard.png");
    Fotis::Sprite x("resources/sprX.png");
    Fotis::Sprite o("resources/sprO.png");

    bool xPiece = true;

    Vector2 mousePosition;

    // Load shader and setup location points and values
    Shader shader = LoadShader(0, TextFormat("resources/shaders/glsl%i/blur_darken.fs", GLSL_VERSION));
    Shader fontShader = LoadShader(0, TextFormat("resources/shaders/glsl%i/outlineSDF.fs", GLSL_VERSION));

    Vector2 centerOriginPosition = { screenWidth/2, screenHeight/3 };
    Fotis::UI title("Tic Tac Toe", 28, centerOriginPosition);

    centerOriginPosition = { screenWidth/2, screenHeight/3 * 2 };
    Fotis::UI subTitle("By: Jordan McClintock", 12, centerOriginPosition);

    centerOriginPosition = { screenWidth/2, screenHeight/4 * 3 };
    Fotis::UI startButton("Start!", 10, centerOriginPosition);

    centerOriginPosition = { screenWidth/2, screenHeight/3 };
    Fotis::UI gameOver("Game Over!", 28, centerOriginPosition);

    centerOriginPosition = { screenWidth/2, screenHeight/4 * 3 };
    Fotis::UI startOverButton("Play Again?", 10, centerOriginPosition);    

    Color startButtonColor = BLACK;

    GAME_STATE gameState = START_MENU;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        bool mousePressed = false;
        mousePosition = GetMousePosition();
        // Input
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            mousePressed = true;

        // Update
        if (mousePressed && gameState == GAME_RUNNING)
        {
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
        }

        if (startButton.Hover(mousePosition))
        {
            startButtonColor = GRAY;
            if (mousePressed)
            {
                gameState = GAME_RUNNING;
            }
        }
        else
        {
            startButtonColor = BLACK;
        }

        if (startOverButton.Hover(mousePosition))
        {
            startButtonColor = GRAY;
            if (mousePressed)
            {
                gameState = GAME_RUNNING;
                grid.Reset();
            }
        }
        else
        {
            startButtonColor = BLACK;
        }        
        

        std::vector<Fotis::Cell> line = grid.CheckWinner();
        bool catsGame = false;
        if (line.size() != 3)
            catsGame = grid.CheckCatsGame();
        

        // Render
        BeginDrawing();

            // float deltaTime = GetFrameTime();

            if (gameState == START_MENU)
            {
                BeginShaderMode(shader);
                    ClearBackground(RAYWHITE);
                    grid.Draw();
                EndShaderMode();
            }
            else
            {
                ClearBackground(RAYWHITE);
                grid.Draw();
            }


            if (line.size() == 3)
            {
                float startX = line.front().box.width / 2 +  line.front().box.x;
                float startY = line.front().box.height / 2 + line.front().box.y;
                float endX = line.back().box.width / 2 + line.back().box.x;
                float endY = line.back().box.height / 2 + line.back().box.y;

                Vector2 startPos = {startX, startY};
                Vector2 endPos = {endX, endY};

                DrawLineEx(startPos, endPos, 5.0f, BLACK);

                gameState = GAME_OVER;
            }

            if (catsGame)
            {
                Vector2 start = { screenWidth / 3 * 2, screenHeight / 3 };
                Vector2 middle = { 0, screenHeight / 2 };
                Vector2 end = { screenWidth / 3 * 2, screenHeight / 3 * 2 };
                Fotis::GraphicsUtility::DrawLineBezierQuad(start, end, middle, 5.0f, RED);
            }

            if (gameState == START_MENU)
            {
                // NOTE: SDF fonts require a custom SDf shader to compute fragment color
                BeginShaderMode(fontShader);    // Activate SDF font shader
                    title.Draw(BLACK);

                    subTitle.Draw(BLACK);

                    startButton.Draw(startButtonColor);
                EndShaderMode();            // Activate our default shader for next drawings
            }

            if (gameState == GAME_OVER)
            {
                // NOTE: SDF fonts require a custom SDf shader to compute fragment color
                BeginShaderMode(fontShader);    // Activate SDF font shader
                    gameOver.Draw(BLACK);

                    startOverButton.Draw(startButtonColor);
                EndShaderMode();            // Activate our default shader for next drawings                
            }

        EndDrawing();
    }

    CloseWindow();                // Close window and OpenGL context

    return 0;
}