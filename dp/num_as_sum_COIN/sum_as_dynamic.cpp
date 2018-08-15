#include <iostream>
#include <cstdbool>
#include <vector>
using namespace std;

int ways(int);

int main(){
    cout<<ways(6)<<endl;
    return 0;
}

int ways(int n){
    //1,3,5
    vector<int> dp;
    dp.resize(n+1);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    
    for(int i= 3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}