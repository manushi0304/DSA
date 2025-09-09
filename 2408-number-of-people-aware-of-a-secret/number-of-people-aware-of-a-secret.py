class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        MOD=10**9 + 7
        dp=[0]*(n+1)
        dp[1]=1
        share=0
        for day in range(2,n+1):
            if day-delay>=1:
                share=(share+dp[day-delay])%MOD
            if day-forget>=1:
                share=(share-dp[day-forget])%MOD
            dp[day]=share%MOD
        result=sum(dp[max(1, n-forget+1):n+1])%MOD
        return result