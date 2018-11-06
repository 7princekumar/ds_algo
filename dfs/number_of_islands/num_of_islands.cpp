#include <iostream>
#include <vector>
#include <cstdbool>
using namespace std;

int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

bool safe(int mat[50][50], int N, int M, int i, int j, int visited[50][50]){
    if((i<0) || (j<0) || (i>=N) || (j>=M) || (visited[i][j]) || (mat[i][j]==0)){
        return false;
    }
    return true;
}

void dfs(int mat[50][50], int N, int M, int row, int col, int visited[50][50]){
    visited[row][col] = 1;
    // cout<< "i:"<<row << "  j:" <<col << endl;
    //look around, if allowed, go ahead
    int dir = 8;
    for(int i=0; i<dir; i++){
        if(safe(mat, N, M, row + dx[i], col + dy[i], visited)){
            dfs(mat, N, M, row + dx[i], col + dy[i], visited);
        }
    }
}

int get_count(int mat[50][50], int N, int M){
    int visited[50][50] = {0};
    int count = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if((mat[i][j]==1) && (visited[i][j] == 0)){
                count++;
                dfs(mat, N, M, i, j, visited);
                cout<< endl;
            }    
        }
    }
    return count;
}

int main(){
    int N = 5;
    int M = 5;
    int mat[50][50] ={ {1, 1, 0, 0, 0},
                       {0, 1, 0, 0, 1},
                       {1, 0, 0, 1, 1},
                       {0, 0, 0, 0, 0},
                       {1, 0, 1, 0, 1} };

    cout << get_count(mat, N, M) << endl;
    
    return 0;
}