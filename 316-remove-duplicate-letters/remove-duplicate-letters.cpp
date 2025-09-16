class Solution {
public:
  string removeDuplicateLetters(string s) {
    map<char, int> freq;
    for (char c : s) freq[c]++;

    map<char, bool> inResult;
    string result = "";

    for (char c : s) {
        freq[c]--;

        if (inResult[c]) continue;

        // pop from result if lexicographically larger
        while (!result.empty() && c < result.back() && freq[result.back()] > 0) {
            inResult[result.back()] = false;
            result.pop_back();
        }

        result.push_back(c);
        inResult[c] = true;
    }

    return result;
        
    }
};