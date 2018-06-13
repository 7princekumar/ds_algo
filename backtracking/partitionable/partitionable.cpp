#include <iostream>
#include <cstdbool>
#include <vector>
using namespace std;

bool partitionable(vector<int>& , int, int);

int main(){
    vector<int> set; int ele, n;
    cout<<"n: "; cin>> n;
    cout<<"Set: ";
    for(int i=0; i<n; i++){
        cin>> ele;
        set.push_back(ele);
    }

    if(partitionable(set, 0, 0)){
        cout<<"Yes."<< endl;
    }else{
        cout<<"No."<<endl;
    }

    return 0;
}

bool partitionable(vector<int> &rest, int sum1, int sum2){
    if(rest.empty()){
        return sum1==sum2;
    }else{
        int n = rest[0];
        rest.erase(rest.begin());
        bool answer = partitionable(rest, sum1+n, sum2) || partitionable(rest, sum1, sum2+n);
        rest.insert(rest.begin(), n);
        return answer; //this is so, set doesn't change.
    }
}