#include <iostream>
#include <string>
using namespace std;

//Note: dp[i][j] means we're checking s1[i-1] and s2[j-1]

int longest_common_substring_len(string s1, string s2, int dp[30][30]){
    int result = 0;
    for(int i=1; i<=s1.length(); i++){ //note: start from i=1, j=1 ::: i <= s.len()
        for(int j=1; j<=s2.length(); j++){
            
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = 0;
            }
            result = max(result, dp[i][j]);
            
        }
    }
    return result;
}

int main(){
    string s1 = "abCOMMONbbc";
    string s2 = "abcoCOMMONabc"; //COMMON
    int dp[30][30] = {0};
    cout<<"LCSuff Len: "<< longest_common_substring_len(s1, s2, dp)<< endl;
    return 0;
}
