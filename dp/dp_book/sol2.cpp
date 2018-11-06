#include <iostream>
#include <vector>
using namespace std;

#define N 100
int n; 
int a[N] = {1,2,3,4,5,6};
int cf[N];

int go(int pos){
    if(pos == 0) return a[0];
    cf[pos] = a[pos] + go(pos -1);
    return cf[pos];
}


int main(){
    cin >> n;
    cout << go(n-1) << endl;
    return 0;
}