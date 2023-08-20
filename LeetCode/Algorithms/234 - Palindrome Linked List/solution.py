# ==================================================
# Problem  :   234 - Palindrome Linked List
# Run time :   0.943 sec
# Language :   Python3
# ==================================================

DfsResult = namedtuple('DfsResult', ['result', 'forward_flow_current_node', 'total_length'])

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        dfs_result: DfsResult = self.dfs(current_node=head, head=head, current_length=1)
        return dfs_result.result
    
    def dfs(self, current_node: ListNode, head: ListNode, current_length: int):
        if current_node.next is None:
            return DfsResult(current_node.val == head.val, head.next, current_length)
        
        dfs_result: DfsResult = self.dfs(current_node.next, head, current_length+1)

        if current_length <= dfs_result.total_length // 2:
            return dfs_result
        else:
            return DfsResult(result=dfs_result.result and current_node.val == dfs_result.forward_flow_current_node.val,
                forward_flow_current_node=dfs_result.forward_flow_current_node.next,
                total_length=dfs_result.total_length)
