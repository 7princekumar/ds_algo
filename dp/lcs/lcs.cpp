#include <iostream>
#include <string>
using namespace std;

//from left to right
int lcs(string s1, int i, string s2, int j){
    //if end
    if( (i==s2.length()) || (j==s1.length()) ) 
        return 0; 
    //if matches
    if( s1[i]==s2[j] ) 
        return 1 + lcs(s1,i+1, s2, j+1);
    //if does not match
    return max(lcs(s1,i, s2, j+1),lcs(s1,i+1, s2, j));
}

int main(){
    string s1 = "abcbdab";
    string s2 = "bdcaba";
    cout<< "LCS length: "<< lcs(s1, 0, s2, 0)<< endl;
    return 0;
}