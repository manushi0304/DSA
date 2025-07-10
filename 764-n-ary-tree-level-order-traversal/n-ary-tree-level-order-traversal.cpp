/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> res;
    void dfs(Node* node, int level) {
        if (!node) return;
        if (res.size() == level) {
            res.push_back({});
        }
        res[level].push_back(node->val);
        for (Node* child : node->children) {
            dfs(child, level + 1);
        }
    }

    vector<vector<int>> levelOrder(Node* root) {
        dfs(root, 0);
        return res;
    }
};
