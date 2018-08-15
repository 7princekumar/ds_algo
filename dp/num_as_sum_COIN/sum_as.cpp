#include <iostream>
#include<cmath>
using namespace std;

int ways(int n){
    if(n < 0 ){
        return 0;
    }

    if(n < 0){
        return 0;
    }else if(n == 0){
        return 1;
    }else{
        return ways(n-1) + ways(n-3) + ways(n-5);
    }  
}

int main(){
    cout<< ways(6)<< endl;
    return 0;
}