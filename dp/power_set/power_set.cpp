#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print_i_v(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<< v[i]<<" ";
    }
    cout<< endl;
}

void power_set(vector<int> set, vector<int> subset){
    if(set.empty() == true){
        print_i_v(subset);
        return ;
    }else{
        //take last
        if(is_safe(set[set.size() -1], subset)){
            subset.push_back(set.back());
            power_set(set, subset);
        }
        //don't take last
        else{

        }
        
    }
}

int main(){
    int arr[] = {1,2,3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    vector<int> set(begin(arr), end(arr));

    vector<int> subset;
    power_set(set, subset);
    
    return 0;
}