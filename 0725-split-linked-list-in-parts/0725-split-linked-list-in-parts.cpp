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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>parts(k,nullptr);
        int len=0;
        for(ListNode* node=head;node;node=node->next){
            len++;
        }
        int n=len/k;
        int r=len%k;
        ListNode*node=head,*prev=NULL;
        for(int i=0;i<k && node;i++,r--){
            parts[i]=node;
            for(int j=0;j<n+(r>0);j++){
                prev=node;
                node=node->next;
            }
            prev->next=NULL;
        }
        return parts;
    }
};