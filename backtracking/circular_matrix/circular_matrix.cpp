//link: https://www.interviewbit.com/problems/prettyprint/

void solve(vector<vector<int> > &v, int n, int i, int j, int value, int dir){
    if((i<0) || (j<0) || (i>=2*n - 1) || (j>=2*n - 1) || (v[i][j] > 0)){
        //if already a number, new circle - change value, and change dir
        if(value == 1){
            return;
        }
        //if goes out of boundary, change direction and come back one step
        if(dir==1) solve(v, n, i+1, j-1, value, 2);
        if(dir==2) solve(v, n, i-1, j-1, value, 3);
        if(dir==3) solve(v, n, i-1, j+1, value, 4);
        if(dir==4){
            value--;
            solve(v, n, i+1, j+1, value, 1);
        }
        return;
    }else{
        v[i][j] = value;
        if(dir == 1) solve(v, n, i, j+1, value, 1);
        if(dir == 2) solve(v, n, i+1, j, value, 2);
        if(dir == 3) solve(v, n, i, j-1, value, 3);
        if(dir == 4) solve(v, n, i-1, j, value, 4);
    }
}

vector<vector<int> > Solution::prettyPrint(int n) {
    vector<vector<int> > v;
    v.resize(2*n - 1);
    for(int i=0; i< 2*n - 1; i++){
        v[i].resize(2*n - 1);
    }
    
    solve(v, n, 0, 0, n, 1);
    return v;
    
}
