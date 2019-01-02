#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
#define N 100

void print_vi(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void print_array(int a[N], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void go(vector<int> sofar, vector<int> rest){
    if(rest.size() == 0){
        print_vi(sofar);
    }else{
        int last = rest.back();
        rest.pop_back();
        
        go(sofar, rest); //do not include
        sofar.push_back(last); //include
        go(sofar, rest); 
    }
}

void go2(int sofar[N], int m, int rest[N], int n){
    if(n==0){
        print_array(sofar, m);
    }else{
        int last = rest[n-1];

        go2(sofar, m, rest, n-1); //do not include
        sofar[m] = last;
        go2(sofar, m+1, rest, n-1);
    }
}

int main(){
    int n; cin >> n;
    
    vector<int> a;
    int ele;
    for(int i=0; i<n; i++){
        cin >> ele;
        a.push_back(ele);
    }

    vector<int>& rest = a;
    vector<int> sofar;

    cout << "go: " << endl;
    go(sofar, rest);


    //-----------------
    int sofar2[N];
    int rest2[N];
    for(int i=0; i<n; i++){
        rest2[i] = a[i];
    }
    cout << "\ngo2: " << endl;
    go2(sofar2, 0, rest2, n);

    
    return 0;
}