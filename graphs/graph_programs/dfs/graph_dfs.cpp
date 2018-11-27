//http://www.cs.yale.edu/homes/aspnes/pinewiki/DepthFirstSearch.html
#include <iostream>
#include <cstdbool>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

void add_edge(unordered_map<int, vector<int> >& g, int src, int dest){
    g[src].push_back(dest);
}

void create_graph(unordered_map<int, vector<int> >& g){
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);

    add_edge(g, 1, 3);
    add_edge(g, 1, 0);

    add_edge(g, 2, 0);
    add_edge(g, 2, 4);
    add_edge(g, 2, 5);

    add_edge(g, 3, 1);
    add_edge(g, 3, 6);

    add_edge(g, 4, 2);

    add_edge(g, 5, 2);
    add_edge(g, 5, 6);

    add_edge(g, 6, 3);
    add_edge(g, 6, 5);
}

void print_graph(unordered_map<int, vector<int> >& g){
    unordered_map<int, vector<int> > :: iterator itr;
    for(itr = g.begin(); itr != g.end(); itr++){
        cout << itr->first << "-> ";
        vector<int>& adj = itr->second; //alias
        for(int i=0; i < adj.size() ; i++){
            cout<< adj[i] << " ";
        }
        cout << endl;
    }
}


void graph_dfs(unordered_map<int, vector<int> >& g, vector<bool>& visited ,int src){
    cout << src << "-> ";
    visited[src] = true;
    
    vector<int>& adj = g[src];
    for(int i=0; i<adj.size(); i++){
        if(!visited[adj[i]]){
            graph_dfs(g, visited, adj[i]);
        }    
    }
}


int main(){
    unordered_map<int, vector<int> > g;
    create_graph(g);
    cout <<"Graph: \n"; print_graph(g);

    vector<bool> visited;
    for(int i=0; i< g.size(); i++){
        visited.push_back(false);
    }
    cout <<"\nDFS: ";
    graph_dfs(g, visited, 0);
    cout <<endl;
    return 0;
}