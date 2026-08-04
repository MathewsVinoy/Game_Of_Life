#include "raylib.h"
#include "grid.cpp"

int main() {
    Grids grd;
    grd.randomGrid();
    const int screenWidth = 500;
    const int screenHeight = 500;
    const int CELL_SIZE = 20;
    InitWindow(screenWidth, screenHeight, "Game of Life");
	SetTargetFPS(10);

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
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
        grd.evaluation();
        grd.grid.swap(grd.ngd);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}