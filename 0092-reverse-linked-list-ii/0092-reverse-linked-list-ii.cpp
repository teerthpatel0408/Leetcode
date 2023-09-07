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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        for(int i=1;i<left;i++) {
            prev = curr;
            curr = curr -> next;
        }
        ListNode* first = prev;
        ListNode* newend = curr;
        ListNode* nextNode = curr -> next;
        for(int i = 0;i<right - left + 1;i++) {
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
            if(nextNode != NULL) nextNode = nextNode -> next;
        }
        if(first != NULL) first -> next = prev;
        else head = prev;
        newend -> next = curr;
        return head;
    }
};