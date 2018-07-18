#include <iostream>
#include <cstdbool>
#include <vector>

using namespace std;

void print_2d_iv(vector<vector<int> > v){
    cout<<endl;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
} 

bool is_safe(vector<vector<int> > &v, int row, int curr_col){
    //check principle dig.
    for(int i=row, j=curr_col; i>=0 && j>=0; i--, j--){     
        if(v[i][j] == 1){
            return false;
        }
    }

    //check other dig.
    for(int i=row, j=curr_col; i<v.size() && j>=0; i++, j--) {     
        if(v[i][j] == 1){
            return false;
        }
    }

    //horizontal
    for(int i=curr_col; i>=0; i--){
        if(v[row][i] == 1){
            return false;
        }
    }

    return true;

}

bool n_queen(vector<vector<int> > &v, int n, int curr_col){
    if(n<=3){
        return false ;
    }
    //if no more choice left
    if(curr_col >= n){
        print_2d_iv(v);
        return true;
    }else{
        //for all choices
        for(int row=0; row<n; row++){
            //place queen if allowed
            if(is_safe(v, row, curr_col)){
                v[row][curr_col] = 1;
                //go further
                n_queen(v, n, curr_col + 1);
                //remove queen
                v[row][curr_col] = 0;
            }  
        }
    }
    return false;
}

int main(){
    int n; cout<<"N: "; cin>> n;

    //create matrix
    vector<vector<int> > v;
    v.resize(n);
    for(int i=0; i<n; i++){
        v[i].resize(n);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v[i][j] = 0;
        }
    }

    n_queen(v, n, 0);
    return 0;
}