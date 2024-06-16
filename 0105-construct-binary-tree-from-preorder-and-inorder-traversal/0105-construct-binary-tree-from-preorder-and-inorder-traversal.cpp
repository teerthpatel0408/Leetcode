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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root=0;
        return func(preorder,inorder,root,0,inorder.size()-1);
    }

    TreeNode* func(vector<int>& preorder, vector<int>& inorder,int & root,int left,int right){
        if(left>right){
            return NULL;
        }
        int pivot=left;
        while(inorder[pivot]!=preorder[root]){
            pivot++;
        }
        root++;
        TreeNode *newnode=new TreeNode(inorder[pivot]);
        newnode->left=func(preorder,inorder,root,left,pivot-1);
        newnode->right=func(preorder,inorder,root,pivot+1,right);
        return newnode;
    }
};