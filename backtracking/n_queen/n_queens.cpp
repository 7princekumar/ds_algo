#include <iostream>
#include <vector>
#include <cstdbool>

using namespace std;

void solve(int);
bool n_queen(vector<vector<int> >&, int);
bool is_safe(vector<vector<int> >&, int, int);
void place_queen(vector<vector<int> >&, int, int);
void remove_queen(vector<vector<int> >&, int, int);

void print_2d_iv(vector<vector<int> > &v){
    for(int i =0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j] <<' ';
        }
        cout<< endl;
    }
    cout<< endl;
}

int main(){
    cout<<"N: "; int n; cin>> n;
    solve(n);
    return 0;
}

void solve(int n){
    vector<vector<int> > board;
    // matrix.resize(no_of_rows, std::vector<int>(no_of_cols, initial_value));
    board.resize(n, vector<int>(n, 0));
    n_queen(board, 0);
}

bool n_queen(vector<vector<int> > &board, int curr_col){
    int n = board.size();
    if(curr_col >= n) {
        print_2d_iv(board);
        return true;
    } else {
        for(int row=0; row<n; row++){
            if(is_safe(board, row, curr_col) ) {
                place_queen(board, row, curr_col);
                // if (n_queen(board, curr_col+1))   //if only one solution
                //     return true ;
                n_queen(board, curr_col+1);  //for all solution
                remove_queen(board, row, curr_col);
            }
        }
    }
    return false;
}


bool is_safe(vector<vector<int> > &board, int row, int curr_col){
    int n = board.size();
    //for that row
    for(int j=0; j< curr_col; j++){
        if(board[row][j]){
            return false;
        }
    }

    //priciple dig.
    for(int i=row, j=curr_col; i>=0 && j>=0; i--, j--){
        if(board[i][j]){
            return false;
        }
    }

    //other dig.
    for(int i=row, j=curr_col; i<n && j>=0; i++, j--){
        if(board[i][j]){
            return false;
        }
    }

    return true;
}

void place_queen(vector<vector<int> > &board, int row, int curr_col){
    board[row][curr_col] = 1 ;
}

void remove_queen(vector<vector<int> > &board, int row, int curr_col){
    board[row][curr_col] = 0;
}