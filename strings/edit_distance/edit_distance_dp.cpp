//https://www.geeksforgeeks.org/edit-distance-dp-5/
#include <iostream>
#include <vector>
using namespace std;

int min3(int x, int y, int z){
    return min(min(x,y), z);
}


//note: dp[i][j] holds value of s1[i-1] and s2[j-1] //first row, col represents if one string is empty
int edit_distance(string s1, int n, string s2, int m, int dp[30][30]){
    
    //note: i,j represent last char from s1, s2. ie, length of s1 and s2
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            //base
            if(i==0){
                dp[n][m] = j;
            }else if(j==0){
                dp[n][m] = i;
            }
            //main 
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][i-1];
            }else{
                dp[i][j] = 1 + min3(dp[i][j-1], //insert ->ignore that char from s2
                                    dp[i-1][j-1], //replace ->ignore from both
                                    dp[i-1][j]); //remove ->ignore from s1
            }
        }
    }

    return dp[n][m];
}

int main(){
    string s1 = "sunday";
    string s2 = "saturday";
    int dp[30][30] = {0};
    cout<< "Edit Distance: "<< edit_distance(s1, s1.length(), s2, s2.length(), dp) << endl;
    return 0;
}