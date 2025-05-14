#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> PII; // (weight, vertex)

int primMST(int n, vector<vector<PII> >& adj) {
    vector<bool> inMST(n, false);
    priority_queue<PII, vector<PII>, greater<PII> > pq; // Min-heap
    int totalWeight = 0;

    // Start from vertex 0
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += weight;

        cout << "Include vertex: " << u << " with edge weight: " << weight << endl;

        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (!inMST[v]) {
                pq.push(make_pair(w, v));
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<vector<PII> > adj(n); // Adjacency list

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // Undirected graph
    }

    int total = primMST(n, adj);
    cout << "Total weight of MST: " << total << endl;

    return 0;
}
