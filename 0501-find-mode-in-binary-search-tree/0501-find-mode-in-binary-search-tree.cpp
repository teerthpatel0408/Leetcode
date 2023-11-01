/**
 * Definition for a binary tree node.
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

    int maxfreq=0,currfreq=0,pre=INT_MIN;
    vector<int>res;

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
    void inorder(TreeNode*root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        if(pre==root->val){
            currfreq++;
        }
        else{
            currfreq=1;
        }
        if(currfreq>maxfreq){
            res.clear();
            maxfreq=currfreq;
            res.push_back(root->val);

        }
        else if(currfreq==maxfreq){
            res.push_back(root->val);
        }
        pre=root->val;
        inorder(root->right);
    }
};