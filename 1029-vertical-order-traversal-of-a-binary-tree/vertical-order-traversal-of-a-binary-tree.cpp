/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Vector to hold (col, row, value)
        vector<tuple<int, int, int>> nodes;

        // BFS queue: node, row, col
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, row, col] = q.front();
            q.pop();

            if (node) {
                nodes.push_back({col, row, node->val});
                if (node->left)
                    q.push({node->left, row + 1, col - 1});
                if (node->right)
                    q.push({node->right, row + 1, col + 1});
            }
        }

        // Sort nodes: first by col, then row, then value
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> res;
        int prev_col = INT_MIN;

        for (auto [col, row, val] : nodes) {
            if (col != prev_col) {
                res.push_back({});
                prev_col = col;
            }
            res.back().push_back(val);
        }

        return res;
    }
};