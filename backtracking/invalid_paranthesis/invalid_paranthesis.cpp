#include <iostream>
#include <vector>
#include <string>
#include <cstdbool>
#include <set>
#include <queue>

using namespace std;
bool removeInvalidParanthesis(string);
bool isValidParanthesis(string);
bool isParanthesis(char); 


int main(){
    string s; cout<<"Input: "; cin>> s;
    if(!removeInvalidParanthesis(s)){
        cout<<"No result."<<endl;
    }
    return 0 ;
}

bool removeInvalidParanthesis(string s){
    queue<string> q; //for bfs, for minimal removal
    set<string> visited; //for efficiency
    q.push(s);
    while(!q.empty()){
        string curr = q.front(); 
        q.pop();
        if(isValidParanthesis(curr)){
            cout<<"RESULT: "<< curr <<endl ;
            return true;
        }else{
            for(int i=0; i<curr.length(); i++){
                if(isParanthesis(curr[i])){
                    string rest = curr.substr(0,i) + curr.substr(i+1) ;
                    if(visited.find(rest) == visited.end()){
                        q.push(rest);
                        visited.insert(rest);
                    }   
                }
            }
        }
    }
    return false;
    
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