#include <iostream>
#include <vector>
#include <cstdbool>
#include <queue>
#include <map>
using namespace std;
//-----GRAPH UNDIRECTED NON-WEIGHTED----------------------------------------
typedef map<int, vector<int> > GRAPH; //adjacent list
GRAPH g; //graph with adj list

void add_edge(GRAPH& g, int src, int dest){
    g[src].push_back(dest);
}

void graph_dfs(GRAPH& g, vector<bool>& visited, int src){
    cout << src << "->";
    visited[src] = true; //mark it visited

    vector<int>& v = g[src]; //neighbours of src
    for(int i=0; i<v.size(); i++){
        if(!visited[v[i]]){
            graph_dfs(g, visited, v[i]); //go deep
        }
    }

}

void graph_bfs(GRAPH& g, int src){
    //set up visited array
    vector<bool> visited;
    for(int i=0; i< g.size(); i++){
        visited.push_back(false);
    }
    visited[src] = true;

    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        cout << curr << "->";
        
        vector<int> adj_list = g[curr];
        for(int i=0; i<adj_list.size(); i++){
            if(!visited[adj_list[i]]){
                visited[adj_list[i]] = true;
                q.push(adj_list[i]);
            }
        }
    }

}

void print_graph(GRAPH& g){
    GRAPH::iterator itr;
    for(itr= g.begin(); itr!= g.end(); itr++){
        // u--->v1,v2..
        int u = itr->first;
        vector<int> v = itr->second; //neighbours of u

        cout << u << "-> ";
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}
//-------------------------------------------------------------------

void create_graph(GRAPH& g){
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);    
    add_edge(g, 0, 3);    

    add_edge(g, 1, 0);
    add_edge(g, 1, 4);    
    add_edge(g, 1, 5);    

    add_edge(g, 2, 0);
    add_edge(g, 2, 6);

    add_edge(g, 3, 0);
    add_edge(g, 3, 7);

    add_edge(g, 4, 1);
    add_edge(g, 4, 7);

    add_edge(g, 5, 1);
    add_edge(g, 5, 7);

    add_edge(g, 6, 2);
    add_edge(g, 6, 7);

    add_edge(g, 7, 3);
    add_edge(g, 7, 6);
    add_edge(g, 7, 4);
    add_edge(g, 7, 5);
}

int main(){
    create_graph(g);
    cout <<"Graph: \n"; print_graph(g);

    vector<bool> visited;
    for(int i=0; i< g.size(); i++){
        visited.push_back(false);
    }

    cout <<"\nDFS: ";
    graph_dfs(g, visited, 0);

    cout <<"\nBFS: ";
    graph_bfs(g, 0);
    cout <<endl;

    return 0;
}
