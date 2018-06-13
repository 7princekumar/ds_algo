#include <iostream>
#include <string>
using namespace std;

void print_subsets(string, string);

int main(){
    string s;
    // cout<<"Set: "; cin>>s;
    s = "123";
    print_subsets("", s);
    return 0;
}

void print_subsets(string soFar, string rest){
    if(rest == "") {
        cout<< soFar<<endl;
    } else {
        print_subsets(soFar + rest[0], rest.substr(1)); //include 1st char
        print_subsets(soFar, rest.substr(1));           //exclude 1st char
    } 
}