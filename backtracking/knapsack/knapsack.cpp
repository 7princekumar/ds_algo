#include <iostream>
#include <vector>

using namespace std;
struct object{
    int value;
    int weight;
};

int knapsack(vector<struct object>, int, int);

int main(){
    vector<struct object> objects;
    int max_weight;

    int n; cout<<"Number of objects: "; cin>> n;
    objects.resize(n);
    for(int i=0; i<n; i++){
        cout<<"\nObject["<<i+1<<"]: "<< endl;
        cout<<"Value: "; cin>> objects[i].value ;
        cout<<"Weight: "; cin>> objects[i].weight ;
    }

    cout<<endl <<"Max Weight: "; cin>> max_weight;

    cout<<"Best value: "<<knapsack(objects, max_weight, 0)<< endl;

    return 0;
}

int knapsack(vector<struct object> objects, int rem_weight, int best_score){
    if(rem_weight < 0) {
        return 0 ;  //we tried too much weight
    } else {
        int local_best_score = best_score;
        int ob_size = objects.size();
        
        for(int i=0; i<ob_size; i++){  //for all ob, either we take it or don't, try for all.
            struct object ob = objects[i];
            int curr_score = best_score + ob.value;
            int curr_weight = rem_weight - ob.weight;
            objects.erase(objects.begin()+i); //remove for recursion
            curr_score = knapsack(objects, curr_weight, curr_score); 
            //we called knapsack again to store curr_score cuz we don't know if curr_score is indeed the best result considering we take this object.
            //also we don't know wether we took more weight than need. We also have to call somewhere knapsack again, but if we did not store curr_score earlier then where will we do?, so that's why.
            if(curr_score > local_best_score){
                local_best_score = curr_score;
            }
            objects.insert(objects.begin()+i, ob);  //restore
        }
        
        return local_best_score ;
    }

}