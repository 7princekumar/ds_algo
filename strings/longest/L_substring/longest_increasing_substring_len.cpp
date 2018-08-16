#include <iostream>
#include <string>
using namespace std;

int longest_increasing_substring_len(string s){
    int result = 1;
    int local = 1;
    for(int i=1; i<s.length(); i++){ //note: start from i=1
        
        if(s[i] >= s[i-1]){
            local++;
        }else{
            local=1;
        }
        result = max(result, local);
    }
    return result;
}

int main(){
    string s = "1231234593131234567892"; //123456789
    cout<<longest_increasing_substring_len(s)<< endl;
    return 0;
}