//link: https://www.interviewbit.com/problems/next-permutation/

void print_i_v(vector<int> &v){
    cout<<":::: ";
    for(unsigned int j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}

void generate_all_perm(vector<int> sofar, vector<int> rest, vector<vector<int> > &permutations){
    if(rest.size() == 0){
        permutations.push_back(sofar);
        return;
    }else{
        int n = rest.size();
        for(int i=0; i<n; i++){
            vector<int> remaining = rest;
            remaining.erase(remaining.begin() + i);
            sofar.push_back(rest[i]); //include this particular in so-far
            generate_all_perm(sofar, remaining, permutations);
            sofar.pop_back();         //remove this particular from so-far
        }
    }
}

void Solution::nextPermutation(vector<int> &B) {
    vector<int> A = B; //rest
    vector<int> Ar;    //sofar
    sort(A.begin(), A.end());
    vector<vector<int> > permutations; //results
    
    generate_all_perm(Ar, A, permutations);
    //return the next permutation
    bool found = false;
    int index = 0;
    for(int i=0; (i<permutations.size()) && !found; i++){
        if(permutations[i] == B){
            found = true;
            index = i;
        }else{
            found = false;
        }
        if(found){
            B = permutations[(index+1)%permutations.size()];
        }
    }
}
