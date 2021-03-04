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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;
        if (n == 1) return lists[0];
        vector<ListNode*> l(begin(lists), begin(lists) + n / 2);
        vector<ListNode*> r(begin(lists) + n / 2, end(lists));
        ListNode* p = mergeKLists(l);
        ListNode* q = mergeKLists(r);
        ListNode* ans = new ListNode(0);
        ListNode* rr = ans;
        while (p and q) {
            if (p->val <= q->val) {
                rr->next = p;
                p = p->next;
            } else {
                rr->next = q;
                q = q->next;
            }
            rr = rr->next;
        }
        if (p) {
            rr->next = p;
        }
        if (q) {
            rr->next = q;
        }
        return ans->next;
        // vector<ListNode*> l(begin(lists) + 1, end(lists));
        // ListNode* p = mergeKLists(l);
        // ListNode* head = new ListNode(0);
        // ListNode* q = lists[0];
        // ListNode* r = head;
        // while (p and q) {
        //     if (p->val <= q->val) {
        //         r->next = p;
        //         p = p->next;
        //     } else {
        //         r->next = q;
        //         q = q->next;
        //     }
        //     r = r->next;
        // }
        // if (p) {
        //     r->next = p;
        // }
        // if (q) {
        //     r->next = q;
        // }
        // return head->next;
    }
};