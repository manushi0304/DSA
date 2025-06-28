class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        val_index = [(num, idx) for idx, num in enumerate(nums)]
    # Find k largest elements by value
        largest = heapq.nlargest(k, val_index, key=lambda x: x[0])
    # Sort selected elements by original index to preserve order
        largest.sort(key=lambda x: x[1])
    # Extract values
        return [val for val, idx in largest]