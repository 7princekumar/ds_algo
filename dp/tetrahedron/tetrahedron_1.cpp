//with dp
#include <iostream>
#include <cstdbool>
#include <vector>
#include <algorithm>
using namespace std;
#define N 10

#define A 0
#define B 1
#define C 2
#define D 3

int dp[4][4][N];
int visited[4][4][N]; //to see if we have seen that state, if yes, take it from dp

void print_i_2v(int dp[4][4][N], int steps){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<steps; k++){
                cout << dp[i][j][k] << " ";
            }
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;
}


int go(int src, int dest, int steps){
    if(steps == 0){
        if(src == dest) return 1;
        return 0;
    }

    int& ans = dp[src][dest][steps];
    if(visited[src][dest][steps]){
        return ans;
    }else{
        visited[src][dest][steps] = 1;
    }
    ans = 0;
    for(int i=0; i<4; i++){
        if(i != src){
            ans += go(i, dest, steps-1);
        }
    }
    
    return ans;
}

int solve(int n){
    return go(D, D, n);
}

int main(){
    int n; cin >> n;
    cout << solve(n) << endl;
    print_i_2v(dp, n);
    return 0;
}