class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1, right=*max_element(piles.begin(), piles.end());

        while(left< right){
            int mid=left+(right-left)/2;
            int hour=0;

            for(int pile: piles){
                hour+=(pile+mid-1)/mid;
            }
            if(hour>h){
                left=mid+1;
            }
            else right=mid;
        }
        return left;
    }
};