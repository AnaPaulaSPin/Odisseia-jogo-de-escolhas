#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Teste");

    SetTargetFPS(60);
    Image minhaImagem = LoadImage("Carro.png"); 
    ImageResize(&minhaImagem, 200, 200); // reduz para 200x200
    Texture2D textura = LoadTextureFromImage(minhaImagem); 
    UnloadImage(minhaImagem); 
    
    float x = 0;                // começa no canto esquerdo
    float y = 300;              // posição vertical fixa
    float velocidade = 5.0f;    // pixels por quadro


    // Main game loop
    while (!WindowShouldClose())
    {
        x += velocidade; 
        
        if (x > GetScreenWidth()) {
            x = -textura.width;    // começa do lado esquerdo de fora da tela
        }
        
        BeginDrawing();

            ClearBackground(PINK);
              
            DrawText("INICIANDO!!", 270, 100, 50, BLACK);
            DrawTexture(textura, x, y,  WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    UnloadTexture(textura);
    CloseWindow();        

    return 0;
}