#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Disjoint Set Union (Union-Find)
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if(xr == yr) return false;

        if(rank[xr] < rank[yr])
            parent[xr] = yr;
        else if(rank[xr] > rank[yr])
            parent[yr] = xr;
        else {
            parent[yr] = xr;
            rank[xr]++;
        }
        return true;
    }
};

// Kruskal's Algorithm
int kruskalMST(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int mst_weight = 0;

    for(const Edge& edge : edges) {
        if(dsu.unite(edge.u, edge.v)) {
            mst_weight += edge.weight;
            cout << "Edge: (" << edge.u << ", " << edge.v << ") -> " << edge.weight << endl;
        }
    }

    return mst_weight;
}

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<Edge> edges(e);
    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < e; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int total_weight = kruskalMST(n, edges);
    cout << "Total weight of MST: " << total_weight << endl;

    return 0;
}
