class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        n=len(arr)
        for i in range(n):
            missing =arr[i]-(i+1)
            if missing>=k:
                return k+i
        return k+n 
