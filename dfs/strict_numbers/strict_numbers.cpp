//number of stepping stones of particular length
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void dfs(int N, int M, long curr_num, long& count){
    if(curr_num > M) return;
    if((N <= curr_num) && (curr_num <= M)){
        count++;
    }
    
    if(curr_num == 0){
        for(int i=1; i<=9; i++){
            dfs(N, M, curr_num * 10 + i, count);
        }
        return; //last return 
    }

    int last_digit = curr_num % 10;
    if(last_digit == 0){
        dfs(N, M, curr_num * 10 + 1, count);
    }else if(last_digit == 9){
        dfs(N, M, curr_num * 10 + 8, count);
    }else{
        dfs(N, M, (curr_num * 10) + (last_digit - 1), count);
        dfs(N, M, (curr_num * 10) + (last_digit + 1), count);
    }
    return;
}

long count_strict_numbers(int num_digits) {
    // if(num_digits == 0) return 0;
    // if(num_digits == 1) return 9;
    // if(num_digits == 2) return 17;

    int N = pow(10, num_digits-1);
    int M = pow(10, num_digits) - 1;

    long count = 0;
    dfs(N, M, 0, count);
    
    return count;
}

int main(){
    int num_digits;
    cin >> num_digits;
    cout << count_strict_numbers(num_digits) << endl;
    return 0;
}