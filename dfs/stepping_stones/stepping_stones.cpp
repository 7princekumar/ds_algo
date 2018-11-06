//get the count of stepping stones integers between specified range
#include <iostream>
#include <vector>
#include <cstdbool>
using namespace std;

void print_i_v(vector<int>& v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i] <<" ";
    }
    cout << endl;
}

void stepping_stones(int N, int M, int curr_num, vector<int>& v){
    //exit point
    if(curr_num > M){
        return;
    }
    //if in range, add it to solution vector
    if((N <= curr_num) && (curr_num <= M)){
        v.push_back(curr_num);
    }

    //start
    if(curr_num == 0){ //we can go to 9 places from here
        for(int i=1; i<=9; i++){
            stepping_stones(N, M, curr_num * 10 + i, v);
        }
        return; //LAST return statement to be executed by this program
    }

    //do dfs for curr_num after they have become min of 2 digits
    //3 cases.
    int last_digit = curr_num % 10;
    if(last_digit == 0){
        stepping_stones(N, M, curr_num * 10 + 1, v);
    }else if(last_digit == 9){
        stepping_stones(N, M, curr_num * 10 + 8, v);
    }else{
        stepping_stones(N, M, (curr_num * 10) + (last_digit -1), v);
        stepping_stones(N, M, (curr_num * 10) + (last_digit +1), v);
    }
    return; //will never be executed, but still just in case
}   

int main(){
    int N, M;
    cout<< "Starting Range(N): "; cin >> N;
    cout<< "Ending Range(N)  : "; cin >> M;
    
    vector<int> v; //holds all stepping stones btw specified range
    stepping_stones(N, M, 0, v);
    
    cout<<v.size() <<" Stepping stones found."<< endl;
    print_i_v(v);
    return 0;
}