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

string rev_string(string s){
    int i=0; int j = s.length();
    while(i<j){
        while(!isalpha(s[i])){
            i++;
        }
        while(!isalpha(s[j])){
            j--;
        }
        swap(s[i], s[j]);
        i++; j--;
        
    }
    return s;
}

int main(){
    char ch1[20];
    char ch2[20];
    char *p;

    p = strstr(ch1, ch2);
    if(p){
        cout<< p<< endl;
        printf("%s", p);
    }

    string s1 = "hello wo1rld this is dad ##3 hell8ahh";
    vector<string> s;
    string temp;
    for(int i=0; i<s1.length(); i++){
        if(s1[i] != ' '){
            temp.push_back(s1[i]);
        }else{
            s.push_back(rev_string(temp));
            temp.clear();
        }
        if(i == s1.length()-1){
            s.push_back(rev_string(temp));
        }
    }

    print_i_v(s);

    return 0;
}