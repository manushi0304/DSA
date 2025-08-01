class Solution {
public:
    void dfs(vector<int>& visited, vector<vector<int>>& graph, int node) {
        visited[node] = 1;
        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                dfs(visited, graph, nbr);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n, 0);
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(visited, graph, source);
        return visited[destination];
    }
};
