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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *curr = head, *end = head;

        for (int i = 0; i < n; i++)
            end = end->next;

        if (!end) {
            head = head->next;
            delete curr;
            return head;
        }

        while (end->next)
            curr = curr->next, 
            end = end->next;

        end = curr->next;
        curr->next = end->next;

        delete end;
        return head;
        
    }
};