#include <iostream>
#include <vector>
#include <cstdbool>
using namespace std;
#define MAX INT_MAX

bool safe(vector<string>& board, int N, int M, int i, int j, vector<vector<int> >& visited){
    if((i<0) || (j<0) || (i>=N) || (j>=M) || (visited[i][j]) || (board[i][j]=='O')){
        return false;
    }
    return true;
}

void dfs(vector<string>& board, int N, int M, int row, int col, vector<vector<int> >& visited){
    int dx[] = {-1, 0,  1, 0};
    int dy[] = { 0, 1,  0,-1};
    visited[row][col] = 1;
    // cout<< "i:"<<row << "  j:" <<col << endl;
    
    //look around, if allowed, go ahead
    int dir = 4;
    for(int i=0; i<dir; i++){
        if(safe(board, N, M, row + dx[i], col + dy[i], visited)){
            dfs(board, N, M, row + dx[i], col + dy[i], visited);
        }
    }
}


int numberOfWalls(vector<string> board) {
    int N = board.size();
    int M = board[0].length();
    vector<vector<int> > visited;
    visited.resize(N);
    for(int i=0; i<N; i++){
        visited[i].resize(M);
    }
    int count = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if((board[i][j]=='X') && (visited[i][j] == 0)){
                count++;
                dfs(board, N, M, i, j, visited);
                // cout<< endl;
            }    
        }
    }
    return count;
    
}

int main(){
    vector<string> board;
    int N;
    cin >> N;
    for(int i=0; i< N; i++){
        string s;
        cin >> s;
        board.push_back(s);
    }
    cout << numberOfWalls(board) << endl;
    
    return 0;
}

