//applying dp
#include <iostream>
#include <vector>
using namespace std;
#define N 10

int a[N][N];
int n, m;

int dp[N][N];
int vis[N][N];

void print_2d_a(int a[N][N], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<< a[i][j] <<" ";
        }
        cout << endl;
    }
}

void take_input(int a[N][N], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
}

int go(int i, int j){
    if(i>n-1 || j>m-1) return 0; 
    if((i==n-1) && (j==m-1)){
        return a[i][j]; 
    }
    
    int& ans = dp[i][j];
    if(vis[i][j] == 1){
        return ans;
    }
    vis[i][j] = 1;

    
    ans += a[i][j] + max(go(i+1, j), go(i, j+1)); 
    return ans;
}

int main(){
    cin >> n >> m;
    take_input(a, n, m);

    cout << go(0,0) << endl;
    return 0;
}