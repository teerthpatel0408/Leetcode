/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int>ans;
    map<TreeNode*,TreeNode*> parent;
    set<TreeNode*>visit;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root){
            return {};
        }
        findparent(root);
        dfs(target,k);
        return ans;
    }

    void findparent(TreeNode* node){
        if(!node){
            return;
        }
        if(node->left){
            parent[node->left]=node;
            findparent(node->left);
        }
        if(node->right){
            parent[node->right]=node;
            findparent(node->right);
        }
    }

    void dfs(TreeNode*node,int k){
        if(visit.find(node)!=visit.end()){
            return;
        }
        visit.insert(node);
        if(k==0){
            ans.push_back(node->val);
            return;
        }

        if(node->left){
            dfs(node->left,k-1);
        }
        if(node->right){
            dfs(node->right,k-1);
        }
        TreeNode * p=parent[node];
        if(p){
            dfs(p,k-1);
        }
    }
};