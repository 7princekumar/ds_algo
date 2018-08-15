#include <iostream>
using namespace std;

int count_set_bits_v1(int);
int count_set_bits_v2(int); //better

int main(){
    int n; cout<<"n (positive): "; cin>> n;
    cout<<"Set bits_v1: "<< count_set_bits_v1(n)<< endl;
    cout<<"Set bits_v2: "<< count_set_bits_v2(n)<< endl;
    return 0;
}

int count_set_bits_v1(int num){
    unsigned int n = (unsigned int)num;  //so, it works for negative numbers as well. #Hack.
    int count;
    for(count=0; n; n >>= 1){
        count += n & 1;
    }
    return count;
}

int count_set_bits_v2(int n){ //better
    int count;
    for(count=0; n; count++){
        n = n & n-1 ;
    }
    return count;
} 