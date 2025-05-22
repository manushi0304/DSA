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
/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int ans=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[j]+1, dp[i]);
                    ans=max(ans, dp[i]);
                }
            }
        }
        return ans;


    }
}; more optimal solution*/