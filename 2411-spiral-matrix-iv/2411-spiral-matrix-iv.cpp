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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int i = 0, j = 0;
        while (head != NULL){
            if (j < n){
                while (head != NULL && j < n && ans[i][j] == -1){
                    ans[i][j] = head->val;
                    head = head->next;
                    j++;
                }
                if (head == NULL){
                    break;
                }
                i++;
                j--;
            }
            if (i < m){
                while (head != NULL && i < m && ans[i][j] == -1){
                    ans[i][j] = head->val;
                    head = head->next;
                    i++;
                }
                i--;
                j--;
            }
            if (j >= 0){
                while (head != NULL && j >= 0 && ans[i][j] == -1){
                    ans[i][j] = head->val;
                    head = head->next;
                    j--;
                }
                j++;
                i--;
            }
            if (i >= 0){
                while (head != NULL && i >= 0 && ans[i][j] == -1){
                    ans[i][j] = head->val;
                    head = head->next;
                    i--;
                }
                i++;
                j++;
            }
            m--;
            n++;
        }

        return ans;
    }
};