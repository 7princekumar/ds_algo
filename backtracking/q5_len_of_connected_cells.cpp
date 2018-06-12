#include<iostream>
#include<cstdbool>
#define RMAX 5
#define CMAX 5
using namespace std;


int getVal(int A[RMAX][CMAX], int i, int j){
	if(i<0 || i>RMAX || j<0 || j>CMAX){
		return 0;
	}else{
		return A[i][j];
	}
}


//NOTE: maxSize is by reference, and size is by value!!
void findMaxBlock(int A[RMAX][CMAX], int r, int c, int size, bool boolA[RMAX][CMAX], int& maxSize){
	if(r>=RMAX || c>=CMAX)
		return;

	int neighbours[][2] = {
		{-1,0},
		{-1,-1},
		{0,-1},
		{1,-1},
		{0,1},
		{1,1},
		{0,1},
		{-1,1}
	};


	boolA[r][c] = true;
	size++;
	if (size > maxSize){
		maxSize = size;
	}


	for(int i=0; i<9; i++){
		int new_i = r + neighbours[i][0];
		int new_j = c + neighbours[i][1];	
		if(getVal(A, new_i, new_j) && boolA[new_i][new_j]==false ){
			findMaxBlock(A, new_i, new_j, size, boolA, maxSize);
		}
	}

	boolA[r][c] = false;
}



int getMaxOnes(int A[RMAX][CMAX]){
	int size = 0;
	bool boolA[RMAX][CMAX];

	//set boolA to zero
	for(int i=0; i<RMAX; i++){
		for(int j=0; j<CMAX; j++){
			boolA[i][j] = 0;
		}
	}

	int maxSize = 0;
	
	//for all elem of matrix, call getMaxBlock with size = 0
	for(int i=0; i< RMAX; i++){
		for(int j=0; j< CMAX; j++){
			//findMaxBlock(arr, point(x,y), size=0, bool_array, maxSize)
			findMaxBlock(A, i, j, 0, boolA, maxSize);
		}
	}
	return maxSize;
}




int main(){
	//array
	int A[][CMAX] = {
		{1,1,0,1,0},
		{0,0,1,0,0},
		{1,0,1,0,0},
		{1,0,0,0,0},
		{1,0,0,0,0}
	};
	cout<<"Max-Length of connected cell: "<< getMaxOnes(A)<<endl;
	return 0;
}
