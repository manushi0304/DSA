class Solution {
public:
    int getNumofBq(vector<int>& bloomDay, int mid, int k){
        int bq=0;
        int cnt=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{cnt=0;}
        if(cnt==k){
            bq++;
            cnt=0;
        }
        }
        return bq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start=0;
        int end_day=*max_element(bloomDay.begin(), bloomDay.end());
        int minDays=-1;
        while(start<=end_day){
            int mid=start+(end_day-start)/2;

            if(getNumofBq(bloomDay, mid, k)>=m){
                minDays=mid;
                end_day=mid-1;
                
            }
            else{
                start=mid+1;
            }
        }
        return minDays;
    }
};