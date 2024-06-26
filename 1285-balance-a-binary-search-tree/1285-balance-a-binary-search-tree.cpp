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
    vector<TreeNode*>sortedarr;
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return bst(0,sortedarr.size()-1);
    }

    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        sortedarr.push_back(root);
        inorder(root->right);
    }

    TreeNode* bst(int start,int end){
        if(start>end){
            return NULL;
        }
        int mid=(start+end)/2;
        TreeNode* root = sortedarr[mid];
        root->left= bst(start,mid-1);
        root->right= bst(mid+1,end);
        return root; 
    }
};