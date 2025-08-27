class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Convert map to vector of {num, freq}
        vector<pair<int, int>> arr(freq.begin(), freq.end());

        // Sort by frequency (descending)
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Pick top k
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(arr[i].first);
        }

        return result;
    }
};
