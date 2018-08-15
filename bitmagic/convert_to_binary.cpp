#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void print_i_v(vector<unsigned int> binary){
    cout<<"|";
    for(int i=0; i<binary.size(); i++){
        cout<<binary[i]<<"|";
    }
    cout<<endl;
}

vector<unsigned int> get_binary(unsigned int n){
    vector<unsigned int> binary;
    int binary_size = 8;
    for(int i=0; i< binary_size; i++){
        binary.push_back(n & 1);
        n = n >> 1;
    }
    
    reverse(binary.begin(), binary.end() ); //takes O(n)
    return binary;
}

int main(){
    unsigned int n; cout<<"n: "; cin>>n;
    vector<unsigned int> binary;
    binary = get_binary(n);
    print_i_v(binary);

    return 0;
}