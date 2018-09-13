//with dp, using for loop to avoid stack overflow
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

//note: 2 -> 1,0
//1: started from A, reached A (i.e reached same loc from where we started)
//0: started from A, reached some-where else (i.e did not reach same loc from where we started)


int solve(int n){
    int dp[2][N];
    dp[1][0] = 1;
    dp[0][0] = 0;
    for(int steps=1; steps<n+1; steps++){
        dp[1][steps] = 3 * dp[0][steps-1];
        dp[0][steps] = (2 * dp[0][steps-1]) + dp[1][steps-1];
    }
    return dp[1][n];
}

int main(){
    int n; cin >> n;
    cout << solve(n) << endl;
    return 0;
}