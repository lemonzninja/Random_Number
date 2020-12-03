#include "raylib.h"


// Variables Declarations
// -------------------------------
const int screenWidth = 450;
const int screenHeight = 450;

int randomNumber = 0;

// Functions Declarations
// -------------------------------
static void Initialization(void);
static void Update(void);
static void DrawGame(void);
static void UpdateDrawFrame(void);

// Functions
// -------------------------------
static void Initialization(void) // Game Initializations
{
    InitWindow(screenWidth, screenHeight, "");
}

static void Update(void) // Update Game
{
    /*
        Get a random Value form min, max
        When a key is pressed
        can be any number
        can be uesd for lots of stuff
    */
    
    if (IsKeyPressed(KEY_R))
    {
        randomNumber = GetRandomValue(1, 100);
    }


}

static void DrawGame(void) // Draw Game
{
    // Start Drawing
    BeginDrawing();

    ClearBackground(BLACK);
    
    DrawText(TextFormat("Random number: %i", randomNumber), 20, 30, 20, BLUE);

    if (randomNumber > 50)
    {
        DrawText("Your random number is gratter thin 50", 20, 50, 20, GREEN);
    }

    // End Drawing
    EndDrawing();
}

static void UpdateDrawFrame(void) // Update and Draw Game
{
    Update();
    DrawGame();
}

int main(void) // The main function
{
    // Initialization
    //-----------------------
    Initialization();

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update/Draw gameloop
        UpdateDrawFrame();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}