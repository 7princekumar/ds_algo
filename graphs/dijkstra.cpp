#include <iostream>
#include <cstdbool>
#include <vector>
#include <queue> //queue and priority queue
#include <map>
#include <utility> //for pairs
using namespace std;

//GRAPH-------------------
#define INF INT_MAX
typedef pair<int, int> ii; // vertex, weight
typedef map<int, vector<ii> > GRAPH; //graph contains no negative-weight edges,
void add_edge(GRAPH& g, int src, int dest, int wt);
void dfs_graph(GRAPH& g, int src, vector<bool>& visited);
void bfs_graph(GRAPH& g, int src);
void print_graph(GRAPH& g);
void create_graph(GRAPH& g);
void dijkstra(GRAPH& g, int src); //single-source shortest paths
//------------------------

void create_graph(GRAPH& g){
    add_edge(g, 0, 1, 50); // u-------wt------v
    add_edge(g, 0, 2, 100);    
    add_edge(g, 0, 3, 75);    

    add_edge(g, 1, 0, 50);
    add_edge(g, 1, 4, 60);    
    add_edge(g, 1, 5, 80);    

    add_edge(g, 2, 0, 100);
    add_edge(g, 2, 6, 200);

    add_edge(g, 3, 0, 75);
    add_edge(g, 3, 7, 120);

    add_edge(g, 4, 1, 60);
    add_edge(g, 4, 7, 55);

    add_edge(g, 5, 1, 80);
    add_edge(g, 5, 7, 78);

    add_edge(g, 6, 2, 200);
    add_edge(g, 6, 7, 30);

    add_edge(g, 7, 3, 120);
    add_edge(g, 7, 6, 30);
    add_edge(g, 7, 4, 55);
    add_edge(g, 7, 5, 78);
}


int main(){
    GRAPH g;
    create_graph(g);
    cout << "GRAPH: \n"; print_graph(g); cout << endl;

    vector<bool> visited;
    for(int i=0; i < g.size(); i++){
        visited.push_back(false);
    }
    cout << "DFS: "; dfs_graph(g, 0, visited); cout << endl;
    cout << "BFS: "; bfs_graph(g, 0); cout << endl;

    cout << "\nDijkstra: ";
    dijkstra(g, 0); 
    cout << endl;
    return 0;
}


void add_edge(GRAPH& g, int src, int dest, int wt){
    g[src].push_back(make_pair(dest, wt));
}

void print_graph(GRAPH& g){
    GRAPH:: iterator itr;
    for(itr=g.begin(); itr != g.end(); itr++){
        cout << itr->first << ": ";
        vector<ii>& v = itr->second; //neighbours of a vertex
        for(int i=0; i<v.size(); i++){
            cout << v[i].first << "|"<< v[i].second << " -> ";
        }
        cout << endl;
    }
}

void dfs_graph(GRAPH& g, int src, vector<bool>& visited){
    visited[src] = true;
    cout << src << "->";
    vector<ii>& v = g[src];
    for(int i=0; i<v.size(); i++){
        if(!visited[v[i].first]){
            dfs_graph(g, v[i].first, visited);
        }
    }
}

void bfs_graph(GRAPH& g, int src){
    vector<bool> visited;
    for(int i=0; i<g.size(); i++){
        visited.push_back(false);
    }

    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int curr = q.front(); q.pop ();
        cout << curr << "->";
        vector<ii>& v = g[curr];
        for(int i=0;i <v.size(); i++){
            if(!visited[v[i].first]){
                visited[v[i].first] = true;
                q.push(v[i].first);
            }
        }
    }
}


void dijkstra(GRAPH& g, int src){
    vector<int> distance;
    for(int i=0; i<g.size(); i++){
        distance.push_back(INF);
    }
    distance[src] = 0;

    //NOTE: make sure, wt is the first element in pair for pq, 
    //      since we want MIN-Heap according to wt
    priority_queue<ii, vector<ii>, greater<ii> > pq; //min_heap of pair
    pq.push(make_pair(0, src)); //wt as first element in pair
    
    while(!pq.empty()){
        int u = pq.top().second; //min distance vertex
        pq.pop();
        vector<ii>& adj = g[u];
        for(int i=0; i<adj.size(); i++){
            int v  = adj[i].first; 
            int wt = adj[i].second;
            if(distance[v] > distance[u] + wt){
                distance[v] = distance[u] + wt;
                pq.push(make_pair(distance[v], v)); //push it to pq as distance is now not INF
            } 
        }
    }

    cout << "Source: " << src << endl;
    cout << "vertex \tdistance" << endl;
    for(int i=0; i<g.size(); i++){
        cout << i << "\t" << distance[i] << endl;
    }
}