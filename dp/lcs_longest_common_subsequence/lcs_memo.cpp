//LCS - BOTTOM UP using MEMO
#include <iostream>
#include <string>
using namespace std;

void print_2i(int dp[50][50], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<< dp[i][j]<<"  ";
        }
        cout<<endl ; 
    }
}

int lcs(string s1, string s2, int dp[50][50]){
    //start from matching the strings from back
    for(int i= s1.length() - 1; i>=0; i--){
        for(int j= s2.length() -1; j>=0; j--){
    
            dp[i][j] = dp[i+1][j+1]; //take previous score first
            //if match
            if(s1[i] == s2[j]){
                dp[i][j]++;
            }
            //if doesn't match
            else{
                dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    return dp[0][0];
}

int main(){
    string s1 = "abcbdab";
    string s2 = "bdcaba";
    int dp[50][50] = {0}; //though we just wanted to place ZERO in last row and col.
    cout<< "LCS length: "<< lcs(s1, s2, dp)<< endl;

    cout<<"DP Matrix: "<<endl;
    print_2i(dp, s1.length(), s2.length());
    return 0;
}

//Note: dp[i][j] is kinda the max of the three cells towards south east to it.