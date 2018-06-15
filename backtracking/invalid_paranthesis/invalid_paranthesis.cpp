#include <iostream>
#include <vector>
#include <string>
#include <cstdbool>

using namespace std;
bool removeInvalidParanthesis(string);
bool isValidParanthesis(string);
bool isParanthesis(char); 


int main(){
    string s; cout<<"Input: "; cin>> s;
    removeInvalidParanthesis(s);
    return 0 ;
}

bool removeInvalidParanthesis(string s){
    if(isValidParanthesis(s)){
        cout<<"RESULT: "<<s <<endl ;
        return true;
    }else{
        for(int i=0; i<s.length(); i++){
            if(isParanthesis(s[i])){
                string rest = s.substr(0,i) + s.substr(i+1);
                if(removeInvalidParanthesis(rest)){
                    return true;
                }
            }
        }
        return false;
    }
}


bool isValidParanthesis(string s){
    if(s.length() < 2){
        return false ;
    }
    int count = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            count++;
        }else if(s[i] == ')'){
            count--;
        }
        if(count < 0){ //string = )( is wrong, so 'count' will become negative, thus return false
            return false;
        }
    }
    return (count == 0);
}

bool isParanthesis(char c){
    if(c == '(' || c==')'){
        return true;
    }else{
        return false;
    }
}