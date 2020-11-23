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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode* prev = nullptr;
        int cnt = 1;
        ListNode* p = head;
        while (cnt < m) {
            prev = p;
            p = p->next;
            cnt++;
        }
        ListNode* start = p;
        ListNode* q = p->next;
        cnt++;
        while (cnt <= n) {
            ListNode* r = q->next;
            q->next = p;
            p = q;
            q = r;
            cnt++;
        }
        start->next = q;
        if (m != 1) prev->next = p;
        else head = p;
        return head;
    }
};