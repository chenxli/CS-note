/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func reverseList(head *ListNode) *ListNode {
    if head == nil {
        return head
    }
    p := head
    q := p.Next
    p.Next = nil
    for q != nil {
        r := q.Next
        q.Next = p
        p = q
        q = r
    }
    return p
}