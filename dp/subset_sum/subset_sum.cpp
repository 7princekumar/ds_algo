#include <iostream>
#include <vector>

using namespace std;

void print_i_a(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i] <<" ";
    }
    cout<< endl;
}

void print_i_v(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<< " ";
    }
    cout<< endl; 
}

void solution(int arr[], int n, int sum, int &count, vector<int> subset){
    if( (sum <= 0) || (n <=0)){
        if(sum == 0){
            count++;
            print_i_v(subset);
        }
        return;
    }else{
        solution(arr, n-1, sum, count, subset); //don't take
        subset.push_back(arr[n-1]);
        solution(arr, n-1, sum - arr[n-1], count, subset); //take 
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 7; //1,6  2,5  3,4  1,2,4 

    cout<<"array: "; print_i_a(arr, n);
    cout<<"sum: "<<sum<< endl;
    int count = 0;
    vector<int> subset;
    solution(arr, n, sum, count, subset);
    return 0;
}