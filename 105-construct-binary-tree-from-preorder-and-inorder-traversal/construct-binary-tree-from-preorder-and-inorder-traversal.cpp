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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        int preorderIdx = 0;
        return buildTreeHelper(preorder, inorderMap, preorderIdx, 0, inorder.size() - 1);
    }
    
private:
    TreeNode* buildTreeHelper(vector<int>& preorder, 
                             unordered_map<int, int>& inorderMap,
                             int& preorderIdx,
                             int inorderStart, 
                             int inorderEnd) {
        if (inorderStart > inorderEnd || preorderIdx >= preorder.size()) {
            return nullptr;
        }
        int rootVal = preorder[preorderIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int rootIdx = inorderMap[rootVal];
        root->left = buildTreeHelper(preorder, inorderMap, preorderIdx, 
                                   inorderStart, rootIdx - 1);
        root->right = buildTreeHelper(preorder, inorderMap, preorderIdx, 
                                    rootIdx + 1, inorderEnd);
        return root;
    }
};