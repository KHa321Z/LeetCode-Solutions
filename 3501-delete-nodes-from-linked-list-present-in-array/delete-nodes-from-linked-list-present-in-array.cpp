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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> n(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(-1, head);
        head = dummy;

        while (dummy->next != nullptr) 
            if (n.contains(dummy->next->val)) {
                ListNode* temp = dummy->next;
                dummy->next = dummy->next->next;
            } else
                dummy = dummy->next;

        return head->next;

    }
};