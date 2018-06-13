//https://js-algorithms.tutorialhorizon.com/2015/10/23/combinations-of-an-array/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

void print_subsets(int [], int);

int main(){
    int set[] = {1,2,3};
    int set_size = sizeof(set)/sizeof(int);
    print_subsets(set, set_size); 
    return 0;
}

void print_subsets(int set[], int set_size){
    int n = pow(2,set_size);
    for(int i=0; i<n; i++) {  //for each bit combination
        vector<int> subset;
        for(int j=0; j<set_size; j++){  //for each bit in a bit-comb
            if(i & int(pow(2,j))){
                subset.push_back(set[j]);
            }
        }
        for(int e: subset){
            cout<< e<< ',';
        }
        cout<< endl;
    }
}