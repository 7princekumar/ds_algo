#include <iostream>
#include <vector>
using namespace std;

#define N 4
bool solveMaze(int[N][N], int, int, int[N][N]);
void print_maze(int[N][N]);


int main(){
    // 1 -> path
    // 0 -> wall
    int maze[N][N] =  { 
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int solution[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    cout<<"Maze: "<< endl;
    print_maze(maze);
 
    if(solveMaze(maze, 0, 0, solution)){
        cout<<"Solution exits."<<endl;
        cout<<"Solution: "<< endl;
        print_maze(solution);
    }else{
        cout<<"Solution does not exit."<<endl;
    }
    
    return 0;
}


bool solveMaze(int maze[N][N], int row, int col, int solution[N][N]){
    //base case
    if(maze[row][col] == 0){  //wall
        return false;
    }
    if(maze[row][col] == 2){  //already visited
        return false;
    }
    if((row > N-1) || (col > N-1) || (row < 0) || (col < 0)){ //boundary
        return false;
    }
    if((row == N-1) && (col == N-1)){ //reached destination
        solution[row][col] = 1;
        return true;
    }

    maze[row][col] = 2; //mark it visited


    //if path available, move in N/E/S/W fashion
    if(maze[row][col] >= 1){ //path available
        //north
        if(solveMaze(maze, row-1, col, solution)){
            solution[row][col] = 1;
            return true;
        }

        //east
        if(solveMaze(maze, row, col+1, solution)){
            solution[row][col] = 1;
            return true;
        }

        //south
        if(solveMaze(maze, row+1, col, solution)){
            solution[row][col] = 1;
            return true;
        }

        //west
        if(solveMaze(maze, row, col-1, solution)){
            solution[row][col] = 1;
            return true;
        }
    }

    return false;

}

void print_maze(int maze[N][N]){
    cout<< endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<maze[i][j]<< ' ';
        }
        cout<<endl; 
    }
    cout<< endl;
}