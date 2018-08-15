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

void perm(string soFar, string rest){
    if(rest == "") {
        cout<< soFar<< endl;
    } else {
        for(int i=0; i<rest.length(); i++){
            string remaining = rest.substr(0, i) + rest.substr(i+1);
            perm(soFar + rest[i], remaining);
        }
    }
}