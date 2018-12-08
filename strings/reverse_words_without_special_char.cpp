#include<iostream>
#include <cstdio>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

void print_i_v(vector<string> &v){
    for(unsigned int j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}

string rev_string(string s){ //reverse string and leaves the special char at that position only
    int i=0; int j = s.length();
    while(i<j){
        while(!isalpha(s[i])){ //skip special char from left
            i++;
        }
        while(!isalpha(s[j])){ //skip special char from right
            j--;
        }
        swap(s[i], s[j]); //swap non-special char
        i++; j--;
        
    }
    return s;
}

int main(){
    string s1 = "hello wo1rld this is dad ##3 hell8ahh";
    string s;
    string temp;
    for(int i=0; i<s1.length(); i++){
        if(s1[i] != ' '){
            temp.push_back(s1[i]);
        }else{
            s += rev_string(temp);
            s += " ";
            temp.clear();
        }
        if(i == s1.length()-1){
            s += rev_string(temp);
        }
    }

    cout << s << endl;

    return 0;
}