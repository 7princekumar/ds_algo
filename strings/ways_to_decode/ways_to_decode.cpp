//Link: https://www.interviewbit.com/problems/ways-to-decode/
//Does not pass all test cases
#include <iostream>
#include <string>
using namespace std;

void solve(string& s, int n, int& sum){
    if(n < 0){
        sum++;
        return;
    }else{
        if(s[n] != '0'){
            solve(s, n-1, sum);
        }
        if(n-1 >= 0){ //if not first digit
            string two_digit_str = s.substr(n-1, 2);
            if(stoi(two_digit_str) <= 26){
                solve(s, n-2, sum);
            }
        }
        return;
    }
}

int numDecodings(string s) {
    int sum = 0;
    solve(s, s.length() -1, sum);
    return sum;
}

int main(){
    string s = "1234";
    cout<< numDecodings(s) << endl;
    return 0;
}

