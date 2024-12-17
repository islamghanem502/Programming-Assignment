#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> Edge; // pair<weight, vertex>

void primMST(vector<vector<Edge>>& graph, int V) {
    vector<int> key(V, INT_MAX);     
    vector<bool> inMST(V, false);    
    vector<int> parent(V, -1);       

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; 
    pq.push({0, 0}); // Start from vertex 0 with weight 0
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; 
        pq.pop();

        // If u is already in MST, skip it
        if (inMST[u]) continue;

        inMST[u] = true; // Mark u as included in MST

        // Traverse all adjacent vertices of u
        for (auto& edge : graph[u]) {
            int v = edge.second;
            int weight = edge.first;

            // If v is not in MST and the weight of edge(u, v) is less than the current key value of v
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u; // Update the parent of v to u
            }
        }
    }

    // Output the MST edges
    cout << "Edges in MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " with weight " << key[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Create an adjacency list
    vector<vector<Edge>> graph(V);

    cout << "Enter the edges (u, v, weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({weight, v});
        graph[v].push_back({weight, u}); // Since the graph is undirected
    }

    primMST(graph, V);

    return 0;
}
