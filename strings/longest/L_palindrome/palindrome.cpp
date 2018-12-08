#include <iostream>
#include <string>
using namespace std;

//expands string considering l_marker,r_marker as mid_points
string expand(string s, int l_marker, int r_marker){
    while(l_marker >= 0 && r_marker < s.length() && s[l_marker]==s[r_marker]){
        l_marker--; r_marker++;
    }
    return s.substr(l_marker+1, r_marker - l_marker - 1);
}

//o(n2)
string find_longest_palindrome(string s){
    string curr, ans;
    //odd length
    for(int i=0; i<s.length(); i++){
        curr = expand(s, i, i);
        if(curr.length() > ans.length()){
            ans = curr;
        }
    }

    //even length
    for(int i=0; i<s.length(); i++){
        curr = expand(s, i, i+1);
        if(curr.length() > ans.length()){
            ans = curr;
        }
    }

    return ans;
}

int main(){
    string s; cout << "s: "; cin >> s;
    cout << "longest palindrome_substring: " << find_longest_palindrome(s) << endl;
    return 0;
}