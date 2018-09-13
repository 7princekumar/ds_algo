//with dp, removed redundent memo (as dest remains constant)
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

int dp[2][N];
int visited[2][N]; //to see if we have seen that state, if yes, take it from dp

//note: 2 -> 1,0
//1: started from A, reached A (i.e reached same loc from where we started)
//0: started from A, reached some-where else (i.e did not reach same loc from where we started)

void print_i_2v(int dp[2][N], int steps){
    for(int i=0; i<2; i++){
        for(int k=0; k<steps; k++){
            cout << dp[i][k] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int go(int same, int steps){
    if(steps == 0){
        if(same) return 1;
        return 0;
    }

    int& ans = dp[same][steps];
    if(visited[same][steps] == 1){
        return ans;
    }
    visited[same][steps] = 1;

    if(same){
        ans += 3 * go(0, steps-1);
    }else{
        ans += (2 * go(0, steps-1)) + go(1, steps-1);
    }

    return ans;
}

int solve(int n){
    return go(1, n); //started from some-place, want to reach that place again
}

int main(){
    int n; cin >> n;
    cout << solve(n) << endl;
    print_i_2v(dp, n);
    return 0;
}