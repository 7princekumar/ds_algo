#include <cstdbool>
#include<iostream>
#include<vector>
#define MAX 9

using namespace std;

void print_grid(int grid[MAX][MAX]){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cout<<grid[i][j]<<' ';
        }
        cout<< endl;
    }
}

bool findEmptyLocation(int grid[MAX][MAX], int &er, int &ec){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(!grid[i][j]){
                er = i;
                ec = j;
                return true;
            }
        }
    }
    return false;
}

bool noConflict(int grid[MAX][MAX], int er, int ec, int num){
    for(int j=0; j<MAX; j++){
        if(grid[er][j] == num){
            return false;
        }
    }

    for(int i=0; i<MAX; i++){
        if(grid[i][ec] == num){
            return false;
        }
    }

    int boxStartRow = er - er%3;
    int boxStartCol = ec - ec%3;
    for(int i=boxStartRow; i< boxStartRow+3; i++){
        for(int j=boxStartCol; j< boxStartCol+3; j++){
            if(grid[i][j]==num){
                return false;
            }
        }
    }

    return true;
}

bool sudoku_solve(int grid[MAX][MAX]) {
    int er, ec;
    if(!findEmptyLocation(grid, er, ec)){
        print_grid(grid);
        return true;
    }else{
        for(int num=1; num<=MAX; num++){
            if(noConflict(grid, er, ec, num)){
                grid[er][ec] = num;
                if(sudoku_solve(grid)) return true;
                grid[er][ec] = 0;
            }
        }
    }

    return false;
}

int main(void) {
    int n, board[MAX][MAX];
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<MAX;j++) {
            for(int k=0;k<MAX;k++) {
                board[j][k] = 0;
                cin >> board[j][k];
            }
        }
        sudoku_solve(board);
    }
    return 0;
}


/*
 
INPUT:
1
4 0 0 0 0 6 0 0 0
0 6 0 0 0 0 0 0 9
0 0 0 0 0 0 0 0 0
0 0 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 3 0 6 0 0 2 0
1 0 0 0 0 0 9 0 0
8 0 0 0 0 5 0 0 0
0 0 0 0 0 0 0 0 5

*/