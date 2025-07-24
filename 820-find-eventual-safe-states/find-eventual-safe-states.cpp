class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>reversegraph(n);
        vector<int> outDegree(n,0);
        for(int u=0;u<n;++u){
            for(int v:graph[u]){
                reversegraph[v].push_back(u);
                outDegree[u]++;
                
            }
        }
        queue<int>q;
        for(int i=0;i<n;++i){
            if(outDegree[i]==0)
            q.push(i);
        }
        vector<bool>safe(n,false);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe[node]=true;
            for(int parent : reversegraph[node]){
                outDegree[parent]--;
                if(outDegree[parent]==0)
                q.push(parent);
            }
        }
        vector<int>result;
        for(int i=0;i<n;i++){
            if(safe[i])
            result.push_back(i);
        }
return result;
    }
};