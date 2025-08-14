class Solution {
public:
    void backtrack(string &s, int ind, string curr, vector<string>& res){
        if(ind==s.size()){
            res.push_back(curr);
            return;
        }
        char c=s[ind];
        if(isalpha(c)){
            backtrack(s, ind +1 , curr+(char)tolower(c), res);
            backtrack(s, ind +1, curr+(char)toupper(c), res);
        }
        else{
            backtrack(s,ind+1, curr+c, res);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        backtrack(s,0, "", res);
        return res;
    }
};