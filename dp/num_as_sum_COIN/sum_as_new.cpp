#include <iostream>
#include <cstdbool>
#include <vector>
using namespace std;

int ways(vector<int> v, int n){
    if( (n < 0) || (v.size() == 0)){
        return 0;
    }
    if(n == 0){
        return 1;
    }else{
        vector<int> remaining = v;
        remaining.pop_back();
                //   exclude last  +    include last
        return ways(v, n-v.back()) + ways(remaining, n);
    }
}

int main(){
    int n = 6;
    int ele[] = {1,3,5};
    vector<int> v(begin(ele), end(ele));
    cout<<ways(v, n)<<endl;
    return 0;
}