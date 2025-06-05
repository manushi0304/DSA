# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        temp=head
        slow=head
        
        while temp and temp.next:
            temp=temp.next.next
            slow=slow.next
            if temp==slow:
                return True
        return False