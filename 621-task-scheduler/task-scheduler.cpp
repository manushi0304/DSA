class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);
        for(char &ch: tasks){
            mp[ch-'A']++;
        }
        sort(begin(mp), end(mp));
        int maxFreq=mp[25];
        int slots=maxFreq-1;
        int idle=n*slots;
        for(int i=24;i>=0;i--){
            idle-=min(mp[i], slots);

        }
        if(idle>0){
            return tasks.size()+idle;
        }
        return tasks.size();
    }
};