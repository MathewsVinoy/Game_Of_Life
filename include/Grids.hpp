#ifndef GRIDS_HPP
#define GRIDS_HPP

#include <vector>
using namespace std;

class Grids {
public:
    int width = 5;
    int height = 5;
    vector<vector<float>> grid;
    vector<vector<float>> ngd;
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    Grids(); // Constructor declaration

    int rules(int alive, int root);
    void display();
    void evaluation();
    void randomGrid();
};

#endif 