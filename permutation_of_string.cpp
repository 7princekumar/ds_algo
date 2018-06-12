#include <iostream>
#include <string>

using namespace std;
void perm(string soFar, string rem);

int main(){
    string s;
    cout<<"String: "; cin>>s;

    perm("", s);                              
    return 0;
}

void perm(string soFar, string rem){
    if(rem == "") {
        cout<< soFar<< endl;
    } else {
        for(int i=0; i<rem.length(); i++){
            string remaining = rem.substr(0, i) + rem.substr(i+1);
            perm(soFar + rem[i], remaining);
        }
    }
}