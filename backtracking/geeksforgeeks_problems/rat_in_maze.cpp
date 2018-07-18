#include <iostream>
#include <cstdbool>
#include <vector>
#define N 4

using namespace std;

void print_array(int solution[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<< solution[i][j] << " ";
        } 
        cout<< endl;   
    }
    cout<< endl;
}

bool solve(int maze[N][N], int solution[N][N], int row, int col){
    //base cases -> can't go if wall, boundary, already visited(previous path),
    //or reached destination
    if(maze[row][col] == 0){
        return false;
    }
    if(maze[row][col] == 2){
        return false;
    }
    if((row < 0) || (col < 0)  || (row > N-1) || (col > N-1)){
        return false;
    }  
    if((row == N-1) && (col == N-1)){ //end point
        solution[row][col] = 1;
        return true;
    }
    
    //mark it visited
    maze[row][col] = 2;
    solution[row][col] = 1;

    //go next -> N, E, S, W
    if(solve(maze, solution, row-1, col)){
        return true;
    }
    if(solve(maze, solution, row, col+1)){
        return true;
    }
    if(solve(maze, solution, row+1, col)){
        return true;
    }
    if(solve(maze, solution, row, col-1)){
        return true;
    }

    solution[row][col] = 0;
    return false ;


}

int main(){
    // 1 -> path
    // 0 -> wall
    int maze[N][N] =  { 
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 1}
    };

    int solution[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    //start maze from 0,0 position
    solve(maze, solution, 0,0);
    print_array(solution);
    // print_array(maze) ;

    return 0;
}