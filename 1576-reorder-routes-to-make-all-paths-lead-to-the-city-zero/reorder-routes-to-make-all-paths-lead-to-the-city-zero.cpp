class Solution {
public:

    void dfs(int node,vector<vector<int>>&forward, vector<vector<int>>& backward, int & ans , vector<int>& visited){
        visited[node]=1;
        for(int nbr:forward[node]){
            if(!visited[nbr]){
                ans+=1;
                dfs(nbr, forward,backward,ans, visited);
            }
        }
        for(int nbr: backward[node]){
            if(!visited[nbr])
           dfs(nbr, forward,backward,ans, visited);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>forward(n), backward(n);
        vector<int>visited(n);
        for(int i=0;i<connections.size();i++){
        int a =connections[i][0];
        int b=connections[i][1];
        forward[a].push_back(b);
        backward[b].push_back(a);
    }
    int ans=0;
    dfs(0, forward, backward, ans, visited);
    return ans;
    }
};
/*
int main() {
    int n, m;
    cout << "Enter number of cities (n): ";
    cin >> n;
    cout << "Enter number of connections (n - 1): ";
    cin >> m;

    vector<vector<int>> connections(m);
    cout << "Enter the connections (each as: a b):" << endl;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        connections[i] = {a, b};
    }

    Solution sol;
    int result = sol.minReorder(n, connections);
    cout << "Minimum number of roads to reorder: " << result << endl;
    return 0;
}
*/