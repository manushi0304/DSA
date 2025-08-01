class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(n);
        vector<int>ans;

        for(auto & edge: prerequisites){
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(int &x :graph[i]){
                indegree[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(int &x : graph[f]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        if(ans.size()!=n) return {};
        return ans;
    }
};