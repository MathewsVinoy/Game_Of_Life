#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "grid.cpp"
#include "raylib.h"
using namespace std;

int main() {
    Grids grd;
    grd.randomGrid();
    for (int g = 0; g < 10; g++) {
        cout << "Generation: " << g + 1 << "\n";
        grd.display();
        grd.evaluation();
        grd.grid.swap(grd.ngd);
    }
    return 0;
}
