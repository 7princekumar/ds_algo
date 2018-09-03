//https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int a[] = {1,0,1,9,2,3};
    
    int a_size = sizeof(a)/sizeof(a[0]);
    int old_include;
    int include = a[0];
    int exclude = 0;
    for(int i=1; i<a_size; i++){
        old_include = include;
        include = exclude + a[i]; //if include, add in previous exclude
        exclude = max(old_include, exclude); //if exclude, take max of previous include, and exclude
    }
    cout << max(include, exclude);

    return 0;
}