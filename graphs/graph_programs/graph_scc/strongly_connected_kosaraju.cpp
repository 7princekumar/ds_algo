//Strongly conncted components in Directed graph using KOSARAJU ALGO
// O(V+E). takes two dfs traversal
//https://www.geeksforgeeks.org/strongly-connected-components/

#include <iostream>
#include <vector>
#include <cstdbool>
#include <map>
#include <stack>
using namespace std;

//GRAPH----------
typedef map<int, vector<int> > GRAPH;
void add_edge(GRAPH& g, int src, int dest);
void dfs_graph(GRAPH& g, int src, vector<bool>& visited);
void fill_stack(GRAPH& g, int src, vector<bool>& visited, stack<int>& stack);
GRAPH transpose_graph(GRAPH& g);
void scc(GRAPH& g); //scc - strongly connected components
void print_graph(GRAPH& g);
void create_graph(GRAPH& g);
//--------------

// const int V = 5;
// void create_graph(GRAPH& g){
//     add_edge(g, 0, 2);
//     add_edge(g, 0, 3);

//     add_edge(g, 1, 0);

//     add_edge(g, 2, 1);

//     add_edge(g, 3, 4);
// }

const int V = 9;
void create_graph(GRAPH& g){
    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 0);
    add_edge(g, 4, 5);
    add_edge(g, 5, 6);
    add_edge(g, 6, 4);
    add_edge(g, 7, 6);
    add_edge(g, 7, 8);
}


void fill_stack(GRAPH& g, int src, vector<bool>& visited, stack<int>& s){
    visited[src] = true;

    //do dfs(fill_stack) for all it's neighbours
    vector<int>& v = g[src]; //src-->v1,v2,...
    for(int i=0; i<v.size(); i++){
        if(!visited[v[i]]){
            fill_stack(g, v[i], visited, s);
        }
    }
    //when done with neighbors, push it to stack
    s.push(src);
}


void scc(GRAPH& g){
    stack<int> s;
    vector<bool> visited;
    for(int i=0; i<V; i++){
        visited.push_back(false);
    }

    //for all vertices, call dfs and when ended, push it to stack
    for(int i=0; i<V; i++){
        if(!visited[i]){
            fill_stack(g, i, visited, s);
            s.push(i);
        }
    }

    GRAPH tg = transpose_graph(g);
    visited.clear();
    for(int i=0; i<V; i++){
        visited.push_back(false);
    }

    //pop from stack and call dfs on it
    int scc_count = 0;
    while(!s.empty()){
        int curr = s.top(); s.pop();
        if(!visited[curr]){
            dfs_graph(tg, curr, visited);
            scc_count++;
            cout << endl;
        }
    }
    cout << "SCC Count: " << scc_count << endl;
}

int main(){
    GRAPH g;
    create_graph(g);
    cout << "GRAPH:" << endl; print_graph(g);
    cout << "SCC: "  << endl; scc(g);
    return 0;
}


void add_edge(GRAPH& g, int src, int dest){
    g[src].push_back(dest);
}

void dfs_graph(GRAPH& g, int src, vector<bool>& visited){
    visited[src] = true;
    cout << src << " ";

    vector<int>& v = g[src];
    for(int i=0; i<v.size(); i++){
        if(!visited[v[i]]) dfs_graph(g, v[i], visited);
    }
}

GRAPH transpose_graph(GRAPH& g){
    GRAPH tg;
    GRAPH :: iterator itr;
    for(itr = g.begin(); itr != g.end(); itr++){
        vector<int>& v = itr->second;
        for(int i=0; i<v.size(); i++){
            tg[v[i]].push_back(itr->first); // if u--->v, push v into u
        }
    }
    return tg;
}

void print_graph(GRAPH& g){
    GRAPH :: iterator itr;
    for(itr = g.begin(); itr != g.end(); itr++){
        cout << itr->first << ": ";
        vector<int>& v = itr->second;
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

