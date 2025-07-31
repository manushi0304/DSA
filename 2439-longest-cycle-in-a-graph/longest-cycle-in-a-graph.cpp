class Solution {
public:

int longestCycleLen=-1;
void dfs(int cycleLen, int node, vector<int>&curr, vector<int>& visited, vector<int>&edges){
    cycleLen++;
    curr[node]=cycleLen;
    visited[node]=1;
    int nbr=edges[node];
    if(nbr!=-1){
        if(!visited[nbr]){
            dfs(cycleLen, nbr, curr, visited, edges);
        }
        else if(curr[nbr]!=0){
            int currCycle=curr[node]-curr[nbr]+1;
            longestCycleLen=max(longestCycleLen, currCycle);
        }
    }
    curr[node]=0;
}

    int longestCycle(vector<int>& edges) {
     int nodes=edges.size();
     vector<int>visited(nodes,0);
     vector<int>curr(nodes,0);
     for(int i=0;i<=nodes-1;i++){
        if(visited[i]!=1){
            dfs(0,i,curr, visited, edges);
        }
     }   
     return longestCycleLen;
    }
};