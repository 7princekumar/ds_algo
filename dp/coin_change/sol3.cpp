//another faster method - using rec
#include <iostream>
#include <vector>
#include <cstdbool>
using namespace std;

int n, sum;
vector<int> coins;

int go(int pos, int sum){
    if(pos==n) return (sum==0); //boudary that we reached the ans
    if(sum < 0) return 0; //boundary so we don't keep on taking one element forever
    
    int ans = 0;
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