#include "../include/Grids.hpp"
#include "raylib.h"

int main() {
    Grids grd;
    grd.randomGrid();
    SetConfigFlags(FLAG_WINDOW_TOPMOST | FLAG_WINDOW_UNDECORATED);
InitWindow(GetScreenWidth(), GetScreenHeight(), "Borderless fullscreen");

    Camera2D camera = { 0 };
    camera.zoom = 1.0f;
    const int CELL_SIZE = 5;
    camera.offset = (Vector2){ 0.0f, 0.0f };
    camera.target = (Vector2){ 0.0f, 0.0f };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Get mouse position
        Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);

        // Set camera target to mouse position and offset to screen mouse
        // camera.position = GetScreenToWorld2D(GetMousePosition(), camera);

        // Zoom increment based on mouse wheel
        float wheel = GetMouseWheelMove();
        if (wheel != 0) {
            const float zoomIncrement = 0.125f;
            camera.zoom += (wheel * zoomIncrement);
            
            // Clamp zoom to prevent flipping or infinite scaling
            if (camera.zoom < 0.125f) camera.zoom = 0.125f;
            if (camera.zoom > 64.0f) camera.zoom = 64.0f;
        }
        float moveSpeed = 5.0f;

    if (IsKeyDown(KEY_W)) {
        camera.offset.y -= moveSpeed;
    }
    if (IsKeyDown(KEY_A)) {
        camera.offset.x -= moveSpeed;
    }
    if (IsKeyDown(KEY_S)) {
        camera.offset.y += moveSpeed;
    }
    if (IsKeyDown(KEY_D)) {
        camera.offset.x += moveSpeed;
    }
     
        


        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(camera);
        for (int i = 0; i < grd.height; i++) {
            for (int j = 0; j < grd.width; j++) {
                 Rectangle cellRect = {
                    (float)(j * CELL_SIZE),
                    (float)(i * CELL_SIZE),
                    (float)CELL_SIZE,
                    (float)CELL_SIZE
                };
                Color cellColor = grd.grid[i][j] == 1 ? BLACK : RAYWHITE;
                DrawRectangleRec(cellRect, cellColor);
                DrawRectangleLinesEx(cellRect, 1, LIGHTGRAY);
            }
        }
        EndMode2D();
        grd.evaluation();
    grd.grid.swap(grd.ngd);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
