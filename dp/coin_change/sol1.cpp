//using rec, no dp
#include <iostream>
#include <vector>
using namespace std;

int n, sum;
vector<int> coins;

int go(int pos, int sum){
    if(pos == n) return (sum == 0);

    int curr_coin = coins[pos];
    int times = 0;
    int ans = 0;
    while(sum - (times*curr_coin) >= 0){
        ans += go(pos+1, sum - (times*curr_coin));
        times++;
    }
    return ans;
}

int main(){
    int ele;
    cin >> n >> sum;
    for(int i=0; i<n; i++){
        cin >> ele;
        coins.push_back(ele);
    }

    cout << go(0, sum) << endl;
    
    return 0;
}