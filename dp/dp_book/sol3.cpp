#include <iostream>
using namespace std;

int n;

void go(int factor){
    if(factor<=0) return;
    go(factor - 1);

    cout << n*factor << endl;
}

int main(){
    cin >> n;
    go(10);
    return 0;
}