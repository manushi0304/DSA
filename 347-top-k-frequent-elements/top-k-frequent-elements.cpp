class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Min-heap to keep top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (auto &it : freq) {
            minHeap.push({it.second, it.first});  // {frequency, number}
            if (minHeap.size() > k) {
                minHeap.pop();  // remove least frequent
            }
        }

        // Step 3: Extract results
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
