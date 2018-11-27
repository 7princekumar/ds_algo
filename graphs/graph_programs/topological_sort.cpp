#include <iostream>
#include <cstdbool>
#include <vector>
#include <map>
#include <utility>
#include <queue>
using namespace std;

//GRAPH---- (DAG - Directed Acyclic Graph)
typedef map<int, vector<int> > GRAPH;
GRAPH g;
void add_edge(GRAPH& g, int src, int dest);
void dfs_graph(GRAPH& g, int src, vector<bool>& visited);
void bfs_graph(GRAPH& g, int src);
void topological_sort(GRAPH& g);
void print_graph(GRAPH& g);
//---------

void create_graph(GRAPH& g){
    add_edge(g, 0, 2);
    add_edge(g, 0, 3);    
    add_edge(g, 0, 4);    

    add_edge(g, 1, 2);
    add_edge(g, 1, 4);        
    add_edge(g, 1, 7);        

    add_edge(g, 2, 5);

    add_edge(g, 3, 5);
    add_edge(g, 3, 7);

    add_edge(g, 4, 7);

    add_edge(g, 5, 6);

    add_edge(g, 6, 7);
}

void print_vi(vector<int>& v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}



int main(){
    // GRAPH g;
    create_graph(g);
    cout << "GRAPH: " << endl; print_graph(g);
    
    vector<bool> visited;
    for(int i=0; i<g.size(); i++){
        visited.push_back(false);
    }
    cout << "DFS: "; dfs_graph(g, 0, visited);
    cout << endl;
    cout << "BFS: "; bfs_graph(g, 0);
    cout << endl;

    topological_sort(g);
    return 0;
}





//definations
void add_edge(GRAPH& g, int src, int dest){
    g[src].push_back(dest); //directed
}

void dfs_graph(GRAPH& g, int src, vector<bool>& visited){
    visited[src] = true;
    cout << src << "->";

    vector<int>& v = g[src];
    for(int i=0; i<v.size(); i++){
        if(!visited[v[i]]){
            dfs_graph(g, v[i], visited);
        }
    }
}

void bfs_graph(GRAPH& g, int src){
    vector<bool> visited;
    for(int i=0;i < g.size(); i++){
        visited.push_back(false);
    }

    queue<int> q; //for holding vertices for level order traversal
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        cout << curr << "->";
        //add it's neighbours to queue, and mark it visited
        for(int i=0; i<g[curr].size(); i++){
            if(!visited[g[curr][i]]){
                q.push(g[curr][i]);
                visited[g[curr][i]] = true;
            }
        }
    }
}

void print_graph(GRAPH& g){
    GRAPH :: iterator itr;
    for(itr = g.begin(); itr != g.end(); itr++){
        cout << itr->first << ": ";
        for(int j=0; j<itr->second.size(); j++){
            cout << itr->second[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void topological_sort(GRAPH& g){
    vector<bool> visited;
    vector<int>  indegree;
    for(int i=0; i<g.size(); i++){
        visited.push_back(false);
        indegree.push_back(0);
    }

    //calculate indegree
    GRAPH :: iterator itr;
    for(itr = g.begin(); itr!= g.end(); itr++){
        vector<int>& v = itr->second;
        for(int i=0; i<v.size(); i++){
            indegree[v[i]] += 1;
        }
    }
    cout << "Indegree: "; print_vi(indegree);

    cout << "Topological order: ";
    queue<int> q; //fill q with vertices whose indegree is zero
    for(int i=0; i<indegree.size(); i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int curr = q.front(); q.pop();
        cout << curr << "->";

        //now reduce indegree for its neighbours
        vector<int>& v = g[curr];
        for(int i=0; i<v.size(); i++){
            indegree[v[i]]--;
            if(indegree[v[i]] == 0) q.push(v[i]);
        }
    }
    cout << endl;
}