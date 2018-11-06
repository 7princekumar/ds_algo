//https://www.mathopenref.com/coordpolygonarea.html
#include <iostream>
#include <cstdbool>
#include <vector>
#include <cmath>
using namespace std;

float calculate_area(vector<int> X, vector<int> Y){
    X.push_back(X.front());
    Y.push_back(Y.front());
    
    float sum1 = 0;
    float sum2 = 0;
    for(int i=0; i<X.size() - 1; i++){
        sum1 += X[i] * Y[i+1];
        sum2 += Y[i] * X[i+1];
    }
    return abs(sum1 - sum2) / 2;
}

int main(){
    vector<int> X;
    vector<int> Y;
    int n; cout << "n: "; cin >> n;
    int x, y;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }

    cout << "Area: " << calculate_area(X, Y) << endl;
    return 0;
}