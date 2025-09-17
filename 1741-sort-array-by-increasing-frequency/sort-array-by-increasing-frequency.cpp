class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
         unordered_map<int,int> freq;
        for (int num : nums) freq[num]++;
        auto cmp = [&](pair<int,int>& a, pair<int,int>& b){
            if (a.first == b.first) 
                return a.second < b.second; 
            return a.first > b.first;       
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        for (auto &it : freq) {
            pq.push({it.second, it.first});
        }

        vector<int> result;
        while (!pq.empty()) {
            int f = pq.top().first;
            int val = pq.top().second;
            pq.pop();
            for (int i = 0; i < f; i++) {
                result.push_back(val);
            }
        }

        return result;
    }
};