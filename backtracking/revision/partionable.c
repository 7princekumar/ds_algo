/*
logic: 
take two sums: sum1, sum2 (initialised as zero initially)
for each element in the array from the back, try adding it to each sum and
decrease the size of the array.
when the size of the array is zero, check if the sums are equal.
if yes, it's partionable, otherwise no.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100

bool go(int a[N], int n, int sum1, int sum2){
    if(n==-1) return sum1 == sum2;
    return go(a, n-1, sum1-a[n], sum2) || go(a, n-1, sum1, sum2-a[n]);
}

int main(){
    int n;
    printf("n: ");
    scanf("%d", &n);

    int a[N];
    printf("array elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    if(go(a, n-1, 0, 0)){
        printf("Yes.\n");
    }else{
        printf("No.\n");
    }
    return 0;
}