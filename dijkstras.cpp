#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

class Graph {
private:
    int V;
    vector<vector<pii> > adj;

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii> > pq;

        dist[src] = 0;
        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            for (size_t i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i].first;
                int weight = adj[u][i].second;

                if (dist[v] > d + weight) {
                    dist[v] = d + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        cout << "Vertex\tDistance from Source " << src << "\n";
        for (int i = 0; i < V; ++i) {
            cout << i << "\t" << dist[i] << "\n";
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 1);

    g.dijkstra(0);

    return 0;
}
