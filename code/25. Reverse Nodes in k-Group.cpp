/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        ListNode* pre = new ListNode(0);
        pre->next = head;
        int count = 0;
        ListNode* p = pre;
        while (p->next) {
            count++;
            p = p->next;
        }
        int m = count / k;
        ListNode* last = pre;
        while (m) {
            p = last->next;
            ListNode* start = p;
            ListNode* q = p->next;
            for (int i = 1; i < k; i++) {
                ListNode* r = q->next;
                q->next = p;
                p = q;
                q = r;
            }
            last->next = p;
            start->next = q;
            last = start;
            m--;
        }
        return pre->next;
    }
};