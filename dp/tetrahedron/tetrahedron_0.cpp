//pure recursion, no dp
#include <iostream>
#include <cstdbool>
#include <vector>
#include <algorithm>
using namespace std;

#define A 0
#define B 1
#define C 2
#define D 3

int go(int src, int dest, int steps){
    if(steps == 0){
        if(src == dest) return 1;
        return 0;
    }

    int ans = 0;
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
    return 0;
}