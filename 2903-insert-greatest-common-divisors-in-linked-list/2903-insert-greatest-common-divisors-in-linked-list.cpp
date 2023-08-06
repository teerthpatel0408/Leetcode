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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode*tail=head;
        while(head->next!=NULL){
            int a=head->val;
            int b=head->next->val;
            int g=__gcd(a,b);
            ListNode*newnode=new ListNode(g);
            ListNode*temp=head->next;
            head->next=newnode;
            newnode->next=temp;
            head=temp;
        }
        return tail;
    }
};