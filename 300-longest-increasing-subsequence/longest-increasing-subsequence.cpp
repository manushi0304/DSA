class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int num : nums) {
            auto it = lower_bound(sub.begin(), sub.end(), num);
            if (it == sub.end()) {
                sub.push_back(num);  // Extend the largest subsequence
            } else {
                *it = num;  // Replace to maintain the smallest tail
            }
        }
        return sub.size();
    }
};
