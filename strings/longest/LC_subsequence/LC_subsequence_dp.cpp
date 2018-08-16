#include <iostream>
#include <string>
using namespace std;

//from left to right
int lcs(string s1, string s2, int dp[30][30]){
    for(int i=1; i<=s1.length(); i++){
        for(int j=1; j<=s2.length(); j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[s1.length()][s2.length()];
}

int main(){
    int dp[30][30] = {0};
    string s1 = "abcbdab";
    string s2 = "bdcaba";
    cout<< "LCS length: "<< lcs(s1, s2, dp)<< endl;
    return 0;
}