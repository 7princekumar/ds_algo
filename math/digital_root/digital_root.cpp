#include <iostream>
using namespace std;

int digital_sum(int n){
    if(n == 0){
        return 0;
    }else{
        return (n%9 == 0)? 9 : n%6; 
    }
}

int main(){
    int n; cin >> n;
    cout <<"d_sum: "<< digital_sum(n) << endl;
    return 0;
}