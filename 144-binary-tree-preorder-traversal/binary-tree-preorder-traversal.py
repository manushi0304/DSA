# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result=[]
        cur, stack=root, []
        while cur or stack: 
            if cur:
                result.append(cur.val)
                stack.append(cur.right)
                cur=cur.left    
            else:
                cur=stack.pop()
        return result