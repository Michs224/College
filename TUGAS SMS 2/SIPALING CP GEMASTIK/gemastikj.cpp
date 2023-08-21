#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

vector<int> maxWeights;  // Stores the greatest weights for each pair of vertices

void dfs(const Graph& graph, int u, int parent, int maxWeight) {
    maxWeights[u] = maxWeight;  // Update the greatest weight for vertex u

    for (const auto& edge : graph[u]) {
        int v = edge.first;
        int weight = edge.second;

        if (v != parent) {
            int newMaxWeight = max(maxWeight, weight);
            dfs(graph, v, u, newMaxWeight);
        }
    }
}

int calculateSum(const Graph& graph, int n) {
    maxWeights.resize(n + 1);

    // Perform DFS from vertex 1 as the root
    dfs(graph, 1, 0, 0);

    int sum = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            sum += maxWeights[j];
        }
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    Graph graph(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int sum = calculateSum(graph, n);
    cout << sum << endl;

    return 0;
}

