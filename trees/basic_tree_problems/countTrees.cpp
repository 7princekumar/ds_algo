/*
This is not a binary tree programming problem in the ordinary sense 
-- it's more of a math/combinatorics recursion problem that happens to use binary trees.
Suppose you are building an N node binary search tree with the values 1..N. 
How many structurally different binary search trees are there that store those values? 
Write a recursive function that, given the number of distinct values, computes the number 
of structurally unique binary search trees that store those values. 

For example,
Binary Trees Page: 9
countTrees(4) should return 14, since there are 14 structurally unique binary search trees 
that store 1, 2, 3, and 4. The base case is easy, and the recursion is short but dense. 
Your code should not construct any actual trees; it's just a counting problem.

int countTrees(int numKeys) { ...
VIDEO: https://www.youtube.com/watch?v=JrTKVvYhT_k
*/
#include <iostream>
#include <cstdbool>
#include <vector>
using namespace std;

int countBST(int);
int countBST_dynamic(int, vector<int>&);

int main(){
    int n;
    cout<<"N: "; cin>>n;
    cout<<"Number of BST Possible: "<< countBST(n)<<endl;

    vector<int> dp;
    dp.resize(n);
    cout<<"Number of BST Possible(dynamic): "<< countBST_dynamic(n, dp)<<endl;
    return 0;
}

int countBST(int n){
    int sum = 0;
    if(n <= 1 ){
        return 1;
    }else{
        for(int i=1; i<=n; i++){
            sum += countBST(i-1) * countBST(n-i);
        }
    }
    return sum;
}


int countBST_dynamic(int n, vector<int> &dp){
    int sum = 0;
    if(n <= 1){
        return 1;
    }else{
        for(int i=1; i<=n; i++){
            if(dp[i-1] == 0){
                dp[i-1] = countBST_dynamic(i, dp);
            }
            if(dp[n-i] == 0){
                dp[n-i] = countBST_dynamic(n-i, dp);
            }
            sum += dp[i-1] * dp[n-i];
        }
    }
    return sum;
}