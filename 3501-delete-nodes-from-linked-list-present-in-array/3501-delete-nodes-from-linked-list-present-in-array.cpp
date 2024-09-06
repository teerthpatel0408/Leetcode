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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;
        
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        while (current->next != nullptr) {
            if (numSet.find(current->next->val) != numSet.end()) {
                ListNode* toDelete = current->next;
                current->next = current->next->next;
                delete toDelete; 
            } else {
                current = current->next;
            }
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};