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
    void addNums(ListNode* &sum, ListNode* l1, ListNode* l2, int carry) {

        if (!carry && !l1 && !l2)
            return;

        sum = new ListNode(carry);

        if (l1)
            sum->val += l1->val;
        if (l2)
            sum->val += l2->val;

        carry = sum->val / 10;
        sum->val = sum->val % 10;

        addNums(sum->next, (l1 ? l1->next : l1), (l2 ? l2->next : l2), carry);

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* sum = nullptr;
        addNums(sum, l1, l2, 0);

        return sum;

    }
};