#include <iostream>
#include <string>
#include <cstdbool>
using namespace std;

bool is_rotation(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }else{
        s1 = s1 + s1;
        int pos = s1.find(s2);
        if(pos < 0){
            return false;
        }else{
            return true;
        }
    }
}

int main(){
    string s1 = "ABCD";
    string s2 = "CDAB";
    string s3 = "CDSB";
    if(is_rotation(s1, s3)){
        cout<<"Yes."<< endl;
    }else{
        cout<<"No."<< endl;
    }
    return 0;
}