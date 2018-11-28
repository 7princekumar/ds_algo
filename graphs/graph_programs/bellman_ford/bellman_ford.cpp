#include <iostream>
#include <cstdbool>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

void print_vi(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << i << ": " << v[i] << "\n";
    }
    cout << endl;
}

//-------GRAPH-------------
#define INF INT_MAX
const int V = 6;
typedef pair<int, int> ii;
typedef map<int, vector<ii> > GRAPH;
void add_edge(GRAPH& g, int src, int dest, int wt);
void create_graph(GRAPH& g);
void print_graph(GRAPH& g);
void dfs_graph(GRAPH& g, int src, vector<bool>& visited);
void bfs_graph(GRAPH& g, int src);
void bellman_ford(GRAPH& g, int src);


//-------------------------

int main(){
    GRAPH g;
    create_graph(g);
    cout << "Graph:" << endl;
    print_graph(g);
    
    //dfs
    vector<bool> visited;
    for(int i=0; i<V; i++){
        visited.push_back(false);
    }
    cout << "DFS: ";
    dfs_graph(g, 0, visited);
    cout << endl;

    //bfs
    cout << "BFS: ";
    bfs_graph(g, 0);
    cout << endl;

    //bellman
    int src = 0;
    cout << "Shortest distance to all nodes from src: " << src << endl;
    bellman_ford(g, src);
    cout << endl;
    return 0;
}

void add_edge(GRAPH& g, int src, int dest, int wt){
    g[src].push_back(make_pair(dest, wt)); // src-----wt-----dest
}


void create_graph(GRAPH& g){ //directed
    add_edge(g, 0, 1, 5);
    add_edge(g, 0, 3, -2);

    add_edge(g, 1, 2, 1);

    add_edge(g, 2, 4, -1);
    add_edge(g, 2, 5, 3);

    add_edge(g, 3, 1, 2);
    add_edge(g, 3, 2, 4);
    add_edge(g, 3, 4, 4);

    add_edge(g, 4, 5, 1);
}


void print_graph(GRAPH& g){
    GRAPH:: iterator itr;
    for(itr=g.begin(); itr!=g.end(); itr++){
        cout << itr->first << ": ";
        vector<ii>& adj = itr->second;
        for(int i=0; i<adj.size(); i++){
            int v = adj[i].first;
            int wt = adj[i].second;
            cout << v << "|" << wt << "  ";
        }
        cout << endl;
    }
}


void dfs_graph(GRAPH& g, int src, vector<bool>& visited){
    visited[src] = true;
    cout << src << "->";
    vector<ii>& adj = g[src];
    for(int i=0; i<adj.size(); i++){
        int v = adj[i].first;
        if(!visited[v]){
            dfs_graph(g, v, visited);
        }
    }
}



void bfs_graph(GRAPH& g, int src){
    vector<bool> visited;
    for(int i=0; i<V; i++){
        visited.push_back(false);
    }

    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        cout << curr << "->";
        vector<ii>& adj = g[curr];
        for(int i=0; i<adj.size(); i++){
            int v = adj[i].first;
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
            }
        }
    }
}



void bellman_ford(GRAPH& g, int src){
    vector<int> d; //distance
    for(int i=0; i< V; i++){
        d.push_back(INF);
    }
    d[src] = 0; //shortest distance to itself is zero

    int i = 0;
    while(i < V-1){ // repeat N-1 times
        GRAPH:: iterator itr;
        for(itr=g.begin(); itr != g.end(); itr++){ //for each edge
            int u = itr->first;
            vector<ii>& adj = itr->second;
            for(int j=0; j<adj.size(); j++){
                int v = adj[j].first;
                int wt = adj[j].second;
                d[v] = min(d[v], d[u] + wt);  // u---wt---v
            }
            // cout << "iteration: " << i << endl; ///
            // print_vi(d); ///
        }
        i++;
    }

    print_vi(d);
}