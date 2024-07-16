#include <iostream>
#include <limits.h>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#define INF INT_MAX

bool bfs(vector<vector<int>> rGraph, int s, int t, vector<int>& parent) {
    int V = rGraph.size();
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}

int fordFulkerson(vector<vector<int>> graph, int s, int t) {
    int u, v;
    int V = graph.size();
    vector<vector<int>> rGraph = graph;
    vector<int> parent(V);
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INF;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix (row by row):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            string input;
            cin >> input;
            if (input == "INF") {
                graph[i][j] = INF;
            } else {
                stringstream ss(input);
                int weight;
                ss >> weight;
                graph[i][j] = weight;
            }
        }
    }

    int source, sink;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the sink vertex: ";
    cin >> sink;

    cout << "The maximum possible flow is " << fordFulkerson(graph, source, sink) << endl;

    return 0;
}
