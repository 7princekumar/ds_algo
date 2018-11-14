#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdbool>
using namespace std;
typedef long long ll;

int get(string s){
    int count = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'a'){
            count++;
        }
    }
    return count;
}

bool compare(const string& s1,const string & s2){ 
    return ( get(s1) > get(s2) );
}


void print_i_v(vector<string> &v){
    for(unsigned int j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}

int main(){
    ll N;
    cin >> N;
    vector<string> s;   
    string ele;
    for(ll i=0; i<N; i++){
        cin >> ele;
        s.push_back(ele);
    }

    sort(s.begin(), s.end(), compare);
    print_i_v(s);
    
    ll count_ab = 0, count_a = 0, count_b = 0;
    for (ll i = 0; i < s.size(); i++) {
        for(ll j=0; j<s[i].length(); j++){
            if (s[i][j] == 'a')
                count_a++;
            if (s[i][j] == 'b') {
                count_b++; 
                count_ab += count_a; 
            }
        }
        
    }

    cout << count_ab << endl;
}