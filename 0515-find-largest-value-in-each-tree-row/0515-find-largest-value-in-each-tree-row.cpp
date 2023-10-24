/**
 * Definition for a binary tree root.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>ans; 

    void helper(TreeNode * root,int t){
        if(root==NULL){
            return;
        }
        if(ans.size()<t+1){
            ans.push_back(root->val);
        }
        else{
            if(ans[t]<root->val){
                ans[t]=root->val;
            }
        }
        helper(root->left,t+1);
        helper(root->right,t+1);
    }
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        helper(root,0);
        return ans;
    }
};