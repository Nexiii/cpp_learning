#include "raylib.h"
#include <iostream>

int main() {

    const int windowedWidth = 1280;
    const int windowedHeight = 720;


    const int fullscreenWidth = 1920;
    const int fullscreenHeight = 1080;


    InitWindow(windowedWidth, windowedHeight, "raylib");

    Model model = LoadModel("res/pokemon_firered_-_players_room.glb");

    Vector3 modelPosition = { 0.0f, 0.0f, 0.0f };

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 4.0f, 4.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 65.0f;

    SetExitKey(0);
    SetTargetFPS(0);
    bool isFullscreen = false;

    Vector3 rotationAxis = { 1.0f, 1.0f, 1.0f };
    float rotationAngle = 0.0f;

    while (!WindowShouldClose()) {

        UpdateCamera(&camera, CAMERA_ORBITAL);

        if (IsKeyPressed(KEY_F11)) {
            if (!isFullscreen) {
                SetWindowSize(fullscreenWidth, fullscreenHeight);
                ToggleFullscreen();
                isFullscreen = true;
            } else {
                ToggleFullscreen();
                SetWindowSize(windowedWidth, windowedHeight);
                isFullscreen = false;
            }
        }

        // Begin drawing
        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(camera);
        
        // Draw the model
        DrawModelEx(model, modelPosition, rotationAxis, rotationAngle, (Vector3){1.0f, 1.0f, 1.0f}, WHITE);


        EndMode3D();

        DrawText(TextFormat("FPS: %d", GetFPS()), 10, 10, 20, DARKGRAY);

        EndDrawing();
    }


    UnloadModel(model);
    CloseWindow();

    return 0;
}
