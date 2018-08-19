#include <iostream>
#include <vector>
#include <cstdbool>
#include <string>
using namespace std;

//lcs string
int lcs_len(string s1,int i, string s2, int j, string sol, string& ans){
    if(i >= s1.length() || j >= s2.length()){
        if(sol.length() > ans.length()) ans = sol;
        return 0;
    }else{
        if(s1[i] == s2[j]){
            sol.push_back(s1[i]);
            return 1 + lcs_len(s1, i+1, s2, j+1, sol, ans);
        }else{
            return max(lcs_len(s1, i+1, s2, j, sol, ans), lcs_len(s1, i, s2, j+1, sol, ans));
        }
    }
}


int main(){
    string s1 = "abcdef";
    string s2 = "fsbdf";
    string sol, ans;
    int len = lcs_len(s1,0, s2,0, sol, ans);
    cout<< "len: "<< len << endl;
    cout<< "ans: "<< ans << endl;
    return 0;
}