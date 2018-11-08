#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <cstdbool>
using namespace std;

bool is_balanced(string s){
    int count = 0;
    for(int i=0; i<s.length(); i++){
        if((s[i] == '(') || (s[i] == ')')){
            if(s[i] == '(') count++;
            else if(s[i] == ')') count--;
            
            if(count < 0) return false; //   ))((
        }
    }
    return count == 0;
}

vector<string> get_balanced_paranthesis(string s){
    vector<string> results;
    queue<string> q;
    map<string, bool> visited;
    
    q.push(s);
    bool found = false;
    while(!q.empty()){
        string curr = q.front(); q.pop();
        if(visited[curr]) continue;
        visited[curr] = true;

        if(is_balanced(curr)){
            found = true;
            results.push_back(curr);
        }

        if(found) continue;

        for(int i=0; i<curr.length(); i++){
            if(s[i] == '(' || s[i] == ')'){
                string v = curr.substr(0, i) + curr.substr(i+1);
                q.push(v);
            }
        } //for

    } //while
    return results;
}

int main(){
    string s; cin >> s;
    vector<string> results = get_balanced_paranthesis(s);
    cout << "Results: " << endl;
    for(int i=0; i<results.size(); i++){
        cout <<i+1 << ": " << results[i] << endl;
    }
    cout << endl;

    return 0;
}