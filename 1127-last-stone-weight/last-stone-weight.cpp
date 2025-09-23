class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            sort(stones.begin(), stones.end(), greater<int>());
            int x=stones[0];
            int y=stones[1];

            stones.erase(stones.begin());
            stones.erase(stones.begin());
            if(x!=y){
                stones.push_back(x-y);
            }
        }
        return stones.empty()?0:stones[0];
    }
};