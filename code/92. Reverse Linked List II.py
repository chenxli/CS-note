# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if m == n:
            return head
        def reverse(node, m, n):
            t = node 
            if n > 1:
                if m > 1:
                    node.next, t = reverse(node.next, m - 1, n - 1)
                else:
                    t1, t = reverse(node.next, m, n - 1)
                    node.next = t.next
                    t.next = node
                    node, t = t1, node
            return node, t
        return reverse(head, m, n)[0]
        # if m == 1:
        #     cnt = 1
        #     cur, prev = head, None
        #     while cnt <= n:
        #         cur.next, cur, prev = prev, cur.next, cur
        #         cnt += 1
        #     head.next = cur
        #     head = prev
        # else:
        #     cnt = 1
        #     cur, prev = head, None
        #     while cnt < m:
        #         prev = cur
        #         cur = cur.next
        #         cnt += 1
        #     p = cur
        #     cur = cur.next
        #     cnt += 1
        #     while cnt <= n:
        #         cur.next, cur, p = p, cur.next, cur
        #         cnt += 1
        #     prev.next.next = cur
        #     prev.next = p
        # return head
                
        