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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inorderIndex;
         for (int i = 0; i < inorder.size(); ++i) {
             inorderIndex[inorder[i]] = i;
        }
        int postIdx = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, postIdx, inorderIndex);
    }
    TreeNode* build(vector<int>&inorder, vector<int>&postorder ,int inLeft, int inRight, int& postIdx, unordered_map<int,int>& inorderIndex){
        if(inLeft> inRight) return nullptr;

        int rootVal=postorder[postIdx];
        TreeNode* root=new TreeNode(rootVal);

        int idx=inorderIndex[rootVal];
        postIdx--;

        root->right=build(inorder , postorder, idx+1, inRight,postIdx, inorderIndex);
        root->left=build(inorder, postorder,inLeft, idx-1, postIdx, inorderIndex);
        return root;
    }
};