#include <iostream>
#include <string>
using namespace std;

string longer(string s1, string s2){
    if(s1.length() > s2.length())
        return s1;
    else
        return s2;
}

string lcs(string s1, int i, string s2, int j){
    //if end
    if( (i==s2.length()) || (j==s1.length()) ) 
        return ; 
    //if matches
    if( s1[i]==s2[j] ) 
        return (s1[i] + lcs(s1,i+1, s2, j+1));
    //if does not match
    return longer(lcs(s1,i, s2, j+1),lcs(s1,i+1, s2, j));
}

int main(){
    string s1 = "abcbdab";
    string s2 = "bdcaba";
    cout<< "LCS String: "<< lcs(s1, 0, s2, 0)<< endl;
    return 0;
}