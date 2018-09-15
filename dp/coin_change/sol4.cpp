//another faster method - using dp
#include <iostream>
#include <vector>
#include <cstdbool>
using namespace std;
const int N = 10000;
int n, sum;
vector<int> coins;
int dp[N][N];
int vis[N][N];

int go(int pos, int sum){
    if(pos==n) return (sum==0); //boudary that we reached the ans
    if(sum < 0) return 0; //boundary so we don't keep on taking one element forever
    
    //dp part
    int& ans = dp[pos][sum];
    if(vis[pos][sum] == 1){
        return ans;
    }
    vis[pos][sum] = 1;

    ans += go(pos, sum-coins[pos]); //take the elemet
    ans += go(pos+1, sum); //don't take the element
    return ans;
}

int main(){
    cin >> n >> sum;
    int ele;
    for(int i=0; i<n; i++){
        cin >> ele;
        coins.push_back(ele);
    }

    cout << go(0, sum) << endl;

    return 0;
}

//