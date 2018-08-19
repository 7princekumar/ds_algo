#include <iostream>
#include <cstdbool>
#include <algorithm>
#include <string>
using namespace std;

int min3(int x, int y, int z){
    return min(min(x,y), z);
}

//note: Even though strings have s.length(), use n,m instead of that to avoid overhead
int edit_distance_rec(string s1, int n, string s2, int m){
    // base case
    if(n == 0){
        return m;
    }
    if(m == 0){
        return n;
    }

    // if match and if doesn't
    if(s1[n-1] == s2[m-1]){
        return edit_distance_rec(s1, n-1, s2, m-1); //if match, remove from both
    }else{
        //insert  in   s1 -> means, matched char of 2nd string, so remove char from s2.
        //replace from s1 -> means, matched both char now, so remove both
        //remove  from s1 -> means, did NOT match anything, just remove from s1
        return 1 + min3(edit_distance_rec(s1, n, s2, m-1), //insert
                        edit_distance_rec(s1, n-1, s2, m-1),   //replace
                        edit_distance_rec(s1, n-1, s2, m));//remove
    }
}

int main(){
    string s1 = "sunday";
    string s2 = "saturday";

    cout<< edit_distance_rec(s1, s1.length(), s2, s2.length()) << endl;
    return 0;
}