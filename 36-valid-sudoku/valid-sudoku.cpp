class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>rows(9), cols(9), boxes(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char num=board[i][j];
                if(num=='.') continue;

                if(rows[i].count(num)) return false;
                rows[i].insert(num);

                if(cols[j].count(num)) return false;
                cols[j].insert(num);

                int boxInd=(i/3)*3 + (j/3);
                if(boxes[boxInd].count(num)) return false;
                boxes[boxInd].insert(num);
            }
        }
        return true;
    }
};