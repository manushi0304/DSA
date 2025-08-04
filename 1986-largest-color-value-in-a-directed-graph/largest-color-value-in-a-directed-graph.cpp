class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        vector<vector<int>> count(n, vector<int>(26, 0));
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int visited = 0, answer = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            visited++;
            int colorIndex = colors[u] - 'a';
            count[u][colorIndex]++;
            answer = max(answer, count[u][colorIndex]);

            for (int v : graph[u]) {
                for (int c = 0; c < 26; ++c) {
                    count[v][c] = max(count[v][c], count[u][c]);
                }
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        return visited == n ? answer : -1;
    }
};
