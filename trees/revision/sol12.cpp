#include <iostream>
#include <vector>
using namespace std;
#define N 100
int dp[N];
int vis[N];

int count_trees(int n){
    if(n==0) return 1;
    if(n==1) return 1;
    if(n==2) return 2;
    
    int& ans = dp[n];
    if(vis[n] == 1){
        return ans;
    }
    vis[n] = 1;

    for(int i=1; i<=n; i++){
        ans += count_trees(i-1) * count_trees(n-i);
    }
    return ans;
}

int main(){
    int n; cin >> n;
    cout << count_trees(n) << endl;
    return 0;
}