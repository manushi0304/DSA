class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>>maxHeap;
        for(auto &p: points){
            int x=p[0], y=p[1];
            int dist=x*x+y*y;

            maxHeap.push({dist, {x,y}});
            if((int)maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        vector<vector<int>>res;
        while(!maxHeap.empty()){
            auto top=maxHeap.top();
            maxHeap.pop();
            res.push_back({top.second.first, top.second.second});
        }
        return res;
    }
};