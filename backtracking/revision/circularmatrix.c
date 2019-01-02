/*
     1
     |
 4-------2
     |
     3
*/

#include <stdio.h>
#include <stdlib.h>
#define N 100
#define M ((2*n)-1)

void print_array(int a[N][N], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void go(int a[N][N], int n, int value, int i, int j, int dir){
    if(i<0 || i>=M || j<0 || j>=M || a[i][j]>0){
        if(value==1){
            print_array(a, M);
            return;
        }else{
            //change direction if out of boundary
            if(dir == 2) return go(a, n, value, i+1, j-1, 3);
            if(dir == 3) return go(a, n, value, i-1, j-1, 4);
            if(dir == 4) return go(a, n, value, i-1, j+1, 1);
            if(dir == 1) return go(a, n, value -1, i+1, j+1, 2); // change value and dir
        }
    }else{
        a[i][j] = value;
        switch(dir){
            case 1: return go(a, n, value, i-1, j, dir);
            case 2: return go(a, n, value, i, j+1, dir);
            case 3: return go(a, n, value, i+1, j, dir);
            case 4: return go(a, n, value, i, j-1, dir);
            default: printf("Something went wrong\n");
        }
    }
}

int main(){
    int a[N][N] = {0};
    int n; 
    printf("n: ");
    scanf("%d", &n);

    go(a, n, n, 0, 0, 2); // starting from position 0,0 with right as direction
    return 0;
}