class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        alt_even=0
        alt_odd=0
        all_even=0
        all_odd=0

        for num in nums:
            if num%2==0:
                alt_even=max(alt_even, alt_odd+1)
                all_even+=1
            else:
                alt_odd=max(alt_odd, alt_even+1)
                all_odd+=1
        return max(alt_even, alt_odd, all_even, all_odd)