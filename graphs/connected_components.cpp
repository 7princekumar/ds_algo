#include <iostream>
#include <cstdbool>
#include <vector>
#include <map>
using namespace std;

//----GRAPH-----
typedef map<int, vector<int> > GRAPH;
void add_egde(GRAPH& g, int src, int dest);
void dfs_graph(GRAPH& g, int src, vector<bool>& visited);
void print_graph(GRAPH& g);
void create_graph(GRAPH& g);
void connected_components(GRAPH& g);
//---------------

int main(){
    GRAPH g;
    create_graph(g);
    cout << "GRAPH: \n"; print_graph(g);
    
    vector<bool> visited;
    for(int i=0; i<g.size(); i++){
        visited.push_back(false);
    }

    cout << "Connected Components: \n"; connected_components(g);
    return 0;
}


void add_edge(GRAPH& g, int src, int dest){
    g[src].push_back(dest);
}

void dfs_graph(GRAPH& g, int src, vector<bool>& visited){
    visited[src] = true;
    cout << src << "->";

    vector<int>& v = g[src];
    for(int i=0; i<v.size(); i++){
        if(!visited[v[i]]) dfs_graph(g, v[i], visited);
    }
}

void print_graph(GRAPH& g){
    GRAPH :: iterator itr;
    for(itr = g.begin(); itr != g.end(); itr++){
        cout << itr->first << ": ";
        vector<int>& v = itr->second;
        for(int i=0; i <v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void create_graph(GRAPH& g){
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);        

    add_edge(g, 1, 0);    

    add_edge(g, 2, 0);

    add_edge(g, 3, 4);

    add_edge(g, 4, 3);

    add_edge(g, 5, 6);
    add_edge(g, 5, 7);

    add_edge(g, 6, 5);
    add_edge(g, 6, 7);

    add_edge(g, 7, 5);
    add_edge(g, 7, 6);
}

void connected_components(GRAPH& g){
    vector<bool> visited;
    for(int i=0; i<g.size(); i++){
        visited.push_back(false);
    }

    int count = 0;
    GRAPH :: iterator itr;
    for(itr = g.begin(); itr != g.end(); itr++){
        if(!visited[itr->first]){
            dfs_graph(g, itr->first, visited);
            count++; //new 
            cout << endl;
        }
    }

    cout << "Count: " << count << endl;
}