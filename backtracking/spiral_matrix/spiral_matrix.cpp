#include <iostream>
#include <cstdio>
using namespace std;

#define RIGHT 1  //clockwise
#define DOWN 2
#define LEFT 3
#define UP 4

void print_mat(int m[20][20], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%2d\t", m[i][j]);
        }
        cout<<endl;
    }
}

void solve(int m[20][20], int n, int& count, int row, int col, int dir){
    if( (count> n*n) || (row>=n) || (col>= n) || (row<0) || (col<0) || (m[row][col]!=0)){
        return;
    }else{
        m[row][col] = count++;
        if(dir==RIGHT){   
            solve(m,n,count,row, col+1, RIGHT); //succesfull        
            solve(m,n,count,row+1, col, DOWN);  //else turn
        }
        else if(dir==DOWN){  
            solve(m,n,count,row+1, col, DOWN); 
            solve(m,n,count,row, col-1, LEFT);
        }
        else if(dir==LEFT){  
            solve(m,n,count,row, col-1, LEFT); 
            solve(m,n,count,row-1, col, UP);
        }
        else if(dir==UP){ 
            solve(m,n,count,row-1, col, UP); 
            solve(m,n,count,row, col+1, RIGHT);
        }
    }
}

int main(){
    int n; cin>>n;
    
    int m[20][20];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            m[i][j] = 0;
        }
    }
    
    int count = 1,row=0, col=0,dir=RIGHT;
    solve(m, n, count, row, col, dir);
    print_mat(m, n);

    return 0;
}
