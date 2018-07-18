/*
 
INPUT:
1
4 0 0 0 0 6 0 0 0
0 6 0 0 0 0 0 0 9
0 0 0 0 0 0 0 0 0
0 0 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 3 0 6 0 0 2 0
1 0 0 0 0 0 9 0 0
8 0 0 0 0 5 0 0 0
0 0 0 0 0 0 0 0 5

*/

#include <iostream>
#include <cstdbool>
#include <vector>

using namespace std;

bool is_safe(vector<vector<int> > &v, int row, int col, int ele){
    for(int i=0; i<9; i++){
        //check in row
        if(ele == v[row][i]){
            return false ;
        }
        //check in column
        if(ele == v[i][col]){
            return false;
        }
        //check in 3x3 box
        int box_start_row = row - row%3;
        int box_start_col = col - col%3;
        for(int i=box_start_row; i<box_start_row +3; i++){
            for(int j=box_start_col; j<box_start_col +3; j++){
                if(v[i][j] == ele){
                    return false;
                }
            }
        }
    }

    return true;
}

bool get_empty_place(vector<vector<int> > &v, int &row, int &col){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(v[i][j] == 0){
                row = i;
                col = j;
                return true ;
            }
        }
    }
    return false;
}

void print_2d_iv(vector<vector<int> > &v){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout<< v[i][j] <<" ";
        }
        cout<<endl;
    }
}

bool solve(vector<vector<int> > &v){
    int row, col;
    //if no more steps
    if(!get_empty_place(v, row, col)){
        print_2d_iv(v);
        return true;
    }else{
        for(int ele=1; ele<=9; ele++){
            if(is_safe(v, row, col, ele)){
                //place it
                v[row][col] = ele;
                //go further
                if(solve(v)){
                    return true;
                }
                //remove it
                v[row][col] = 0;
            }
        } 
    }
    return false ;
}

int main(){
    vector<vector<int> >grid;
    grid.resize(9);

    cout<< "Sudoku Input: "<< endl;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int ele; cin>> ele;
            grid[i].push_back(ele) ;
        }
    }
    
    cout<< "Output: "<<endl;
    solve(grid);


    return 0;
}