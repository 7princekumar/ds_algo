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


//from right to left
int lcs(string s1, string s2, int dp[50][50]){
    //start from matching the strings from back
    for(int i= s1.length() - 1; i>=0; i--){
        for(int j= s2.length() -1; j>=0; j--){
    
            dp[i][j] = dp[i+1][j+1]; //take previous score first
            //if match, increase the score
            if(s1[i] == s2[j]){
                dp[i][j]++;
            }
            //if doesn't match, take the max from right or bottom
            else{
                dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    return dp[0][0];
}

void get_all_lcs_string(string s1, string s2, int dp[50][50], string sol, int i, int j, int len){
    if( sol.length() == len){
        cout<<sol<<endl;
        return;
    }
    //if s1[i] == s2[j], then include this character in solution
    if(s1[i] == s2[j]){
        //sol.push_back(s1[i]);
        get_all_lcs_string(s1, s2, dp, sol + s1[i], i+1,j+1,len);
        //sol.pop_back();
    }else{
        //compare values of dp[i+1][j] and dp[i][j+1] and go in direction of greater value(if same, towards s1)
        if(dp[i+1][j] > dp[i][j+1]){
            get_all_lcs_string(s1, s2, dp, sol,i+1,j,len);  //go down
        }else if(dp[i+1][j] < dp[i][j+1]){
            get_all_lcs_string(s1, s2, dp, sol,i,j+1,len);  //go right
        }else{
            get_all_lcs_string(s1, s2, dp, sol,i+1,j,len);  //go both ways
            get_all_lcs_string(s1, s2, dp, sol,i,j+1,len);
        }
    }
}

string get_lcs_string(string s1, string s2, int dp[50][50]){
    string sol = "";
    int len = lcs(s1, s2, dp);
    int i=0, j=0;
    while( (i < s1.length()) && (j < s2.length())){
        //if s1[i] == s2[j], then include this character in solution
        if(s1[i] == s2[j]){
            sol.push_back(s1[i]);
            i++; j++;
        }else{
            //compare values of dp[i+1][j] and dp[i][j+1] and go in direction of greater value(if same, towards s1)
            (dp[i+1][j] >= dp[i][j+1]) ? i++ : j++;
        }
    }
    return sol;
}


int main(){
    string s1 = "AGTGATG";
    string s2 = "GTTAG";
    int dp[50][50] = {0}; //though we just wanted to place ZERO in last row and col.
    cout<< "LCS length: "<< lcs(s1, s2, dp)<< endl;
    cout<< "All LCS Strings: \n"; 
    int len = lcs(s1, s2, dp);
    get_all_lcs_string(s1, s2, dp, "",0,0,len);

    cout<<"One LCS: "<< get_lcs_string(s1,s2, dp)<< endl;

    cout<<"DP: "<<endl;
    print_2i(dp, s1.length(), s2.length());
    return 0;
}
