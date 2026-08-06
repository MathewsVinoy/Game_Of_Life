#include <iostream>
#include <cstdlib>
#include "../include/Grids.hpp"
using namespace std;

Grids::Grids() : grid(height, vector<int>(width, 0)), ngd(height, vector<int>(width, 0)) {}

int Grids::rules(int alive, int root) {
    if (root == 1) {
        if (alive < 2 || alive > 3) return 0;
        else return 1;
    } else {
        if (alive == 3) return 1;
        else return 0;
    }
}


void Grids::display() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}


void Grids::evaluation() {
    int nx, ny;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int alive = 0;
            for (int k = 0; k < 8; k++) {
                nx = i + dx[k];
                ny = j + dy[k];
                if (nx >= 0 && nx < height && ny >= 0 && ny < width) {
                    if (grid[nx][ny] == 1) alive++;
                }
            }
            ngd[i][j] = rules(alive, grid[i][j]);
        }
    }
}


void Grids::randomGrid() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}
