class Solution {
public:
    void util(int open,int close,string s,vector<string>& v,int n)
    {
        if(open==n and close==n)
        {
            v.push_back(s);
            return;
        }
        if(open!=n) util(open+1,close,s+"(",v,n);
        if(close<open) util(open,close+1,s+")",v,n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s;
        util(0,0,s,v,n);
        return v;
    }
};