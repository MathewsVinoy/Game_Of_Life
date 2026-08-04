#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int width = 50;
int height = 50;
vector<vector<int>> grid(height,vector<int>(width,0));
vector<vector<int>> new_grid(height,vector<int>(width,0));
vector<int> dx = {-1,-1,-1,0,0,1,1,1};
vector<int> dy = {-1,0,1,-1,1,-1,0,1};


int rules(int alive,int root){
    if (root ==1){
        if(alive < 2)
            return 0;
        else if(alive ==2 || alive == 3)
            return 1;
        else
            return 0;
    }
    else{ 
        if(alive == 3)
            return 1;
        else
            return 0;
    }
}

void display(){
    for (int i=0;i<height;i++){
        for(int j= 0 ;j<width;j++)
            cout<<grid[i][j]<<" ";
        cout<<"\n";
    }
}
void evaluation(){
    int nx,ny;
    for (int i=0;i<height;i++)
        for(int j= 0 ;j<width;j++){
            int alive =0;
            for(int k =0;k<8;k++){
                nx=i+dx[k];
                ny = j+dy[k];
                if(nx>=0 && nx<height && ny>=0 && ny<width)
                    if(grid[nx][ny]==1)
                        alive++;
            }
            new_grid[i][j] =  rules(alive,grid[i][j]);
        }
}

void randomGrid(){
     for (int i=0;i<height;i++)
        for(int j= 0 ;j<width;j++)
            grid[i][j] = rand()%2;
}

int main(){
    int g;
    randomGrid();
    for(g =0;g<10;g++){
        cout<< "Generation: "<< g+1<<"\n";
        display();
        evaluation();
        grid = new_grid;
    }
    return 0;
}
