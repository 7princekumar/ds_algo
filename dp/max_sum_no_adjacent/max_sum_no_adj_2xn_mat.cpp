//https://www.geeksforgeeks.org/maximum-sum-2-x-n-grid-no-two-elements-adjacent/
#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

int main(){
    int a[2][MAX] = {
        {1,2,3,4,5},
        {6,7,8,9,10}
    };

    int include = max(a[0][0], a[1][0]);
    int exclude = 0;
    int n = sizeof(a[0])/sizeof(a[0][0]);

    int old_include;
    for(int i=1; i<n; i++){
        old_include = include;
        //if taking (i)th, add it to the one, where we did not take (i-1)th -> ie exlclude
        include = exclude + max(a[0][i], a[1][i]);
        //if not taking (i)th, take max(where previous was taken, where previous was not taken)
        exclude = max(old_include, exclude);
    }
    cout << max(include, exclude) << endl;

    return 0;
}