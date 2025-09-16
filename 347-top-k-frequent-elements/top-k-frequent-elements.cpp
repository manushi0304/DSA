class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num:nums){
            freq[num]++;
        }
        vector<pair<int, int>>freqVec;
        for(auto &it: freq){
            freqVec.push_back({it.first, it.second});
        }
         sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b) {      return a.second > b.second;});
         vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(freqVec[i].first);
    }

    return result;
    }

};
/*me Complexity (Brute Force)

Counting frequencies → O(n)

Sorting by frequency → O(m log m), where m is number of unique elements.

Collecting k → O(k)

So worst-case → O(n + m log m).
(Since m ≤ n, it can be O(n log n) in worst case.)*/