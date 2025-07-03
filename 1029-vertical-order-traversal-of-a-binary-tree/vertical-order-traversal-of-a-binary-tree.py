# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        node_list=[]
        queue=deque([(root, 0,0)])
        while queue:
            node, row, col= queue.popleft()
            if node:
                node_list.append((col, row, node.val))
                queue.append((node.left, row+1, col-1))
                queue.append((node.right, row+1, col+1))
        node_list.sort()
        res=defaultdict(list) 
        for col, row, value in node_list:
            res[col].append(value)
        return [res[x] for x in sorted(res)]

        