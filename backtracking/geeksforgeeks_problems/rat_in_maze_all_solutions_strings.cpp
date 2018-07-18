#include <iostream>
#include <cstdbool>
#include <vector>
#include <string> 
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

bool solve(int maze[N][N], string solution, int row, int col){
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
        cout<<"Direction: "<< solution<< endl;
        return true;
    }
    
    //mark it visited
    maze[row][col] = 2;
    //go next -> N, E, S, W
    solution.push_back('U');
    solve(maze, solution, row-1, col);
    solution.pop_back();

    solution.push_back('R');
    solve(maze, solution, row, col+1);
    solution.pop_back();

    solution.push_back('S');
    solve(maze, solution, row+1, col);
    solution.pop_back();

    solution.push_back('W');
    solve(maze, solution, row, col-1);
    solution.pop_back();


    maze[row][col] = 1;
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

    string solution = "";

    //start maze from 0,0 position
    print_array(maze) ;
    solve(maze, solution, 0,0);
    // print_array(solution);
    // print_array(maze) ;

    return 0;
}