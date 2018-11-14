#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort
#define MOD 1000000007
//int max= *max_element(v.begin(), v.end());

using namespace std;

void print_i_v(vector<int> &v){
    for(int j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}

string create_string(string s){
    string t = "#";
    for(int i=0; i< s.length(); i++){
        t.push_back(s[i]);
        t.push_back('#');
    }
    return t;
}


int main() {
    string s = "babcbabcbaccba";
    
    int C = 0;
    int R = 0;
    int i;
    int i_mirror;
    
    string T = create_string(s);
    int n = T.length();
    vector<int> P(n);

    for(i = 1; i<n-1; i++){
        i_mirror = 2*C - i; // c - (i-c)

        //calc p[i] //after 1st expantion
        if(R > i){
            int d = R-i;
            P[i] = min(d, P[i_mirror]);
        } else {
            P[i] = 0;
        }

        //expand
        while( T[i + 1 + P[i]] == T[i - 1 -P[i]] ){
            P[i]++ ;
        }

        //reset C,R if necessary,
        if(i +P[i] > R){
            C= i;
            R= i + P[i];
        }
    }

    // Find the maximum element in P.
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 0; i < n; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    
    cout<< s.substr((centerIndex - maxLen)/2, maxLen) <<endl;

    return 0;
}

//