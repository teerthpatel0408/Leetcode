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
    TreeNode * lca(TreeNode*root,int start,int end){
        if(!root){
            return NULL;
        }
        if(root->val==start || root->val==end){
            return root;
        }
        auto l=lca(root->left,start,end);
        auto r=lca(root->right,start,end);
        if(l && r){
            return root;
        }
        return l?l:r;
    }
    bool path(TreeNode *root,int value,string &paths){
        if(!root){
            return false;
        }
        if(root->val==value){
            return true;
        }
        paths+='L';
        auto res=path(root->left,value,paths);
        if(res){
            return true;
        }
        paths.pop_back();
        paths+='R';
        res=path(root->right,value,paths);
        if(res){
            return true;
        }
        paths.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        root=lca(root,startValue,destValue);
        string s1,s2;
        path(root,startValue,s1);
        path(root,destValue,s2);
        for(auto &c:s1){
            c='U';
        }
        return s1+s2;
    }
};