class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int count = 1, currSum = 0;
        for (int num : nums) {
            if (currSum + num > maxSum) {
                count++;
                currSum = num;
            } else {
                currSum += num;
            }
        }
        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, k, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};