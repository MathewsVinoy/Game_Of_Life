#include "../include/Grids.hpp"
#include <iostream>
#include <random>
using namespace std;

class Lenia{
    Grids g;    
    public:
    void randomValue(){
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<double> dis(0.0, 1.0);
        for (int i = 0; i < g.height; i++) {
            for (int j = 0; j < g.width; j++) {
                g.grid[i][j] = dis(gen);
            }
        }
    }

    void display(){
        for (int i = 0; i < g.height; i++) {
            for (int j = 0; j < g.width; j++) {
                cout << g.grid[i][j] << " ";
            }
            cout << "\n";
        }
    }
};
