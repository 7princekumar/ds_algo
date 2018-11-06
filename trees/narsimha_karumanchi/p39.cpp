/*
Given a parent array P, where P[i] indicates the parent of ith node in the tree 
(Assume parent of root node is indicated with -1) Give an algo for finding the 
height or depth of the tree
*/

#include <iostream>
#include <algorithm> //for max
using namespace std;

int P[] = {-1,0,1,6,6,0,0,2,7}; //means node 0 is parent to three children
int n = sizeof(P)/sizeof(P[0]);
int depth = 0;

int main(){
    for(int i=0; i<n; i++){
        int local_depth = 0;
        int j = i;
        while(P[j] != -1){
            local_depth++;
            j = P[j];
        }
        local_depth++; //indicates root node
        depth = max(depth, local_depth);
    }
    cout << depth << endl;
    return 0;
}
