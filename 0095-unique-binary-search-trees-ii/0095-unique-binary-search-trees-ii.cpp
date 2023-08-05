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
    void helper(int start,int end,vector<TreeNode*>&ret,vector<vector<vector<TreeNode*>>>&dp){
        if(start>end){
            ret.push_back(NULL);
            return;
        }
        if (!dp[start-1][end-1].empty())  {
        ret = dp[start-1][end-1]; return;
    }
        for(int i=start;i<=end;i++){
            vector<TreeNode*>lefttree;
            vector<TreeNode*>righttree;
            helper(start,i-1,lefttree,dp);
            helper(i+1,end,righttree,dp);
            for(int j=0;j<lefttree.size();j++){
                for(int k=0;k<righttree.size();k++){
                    TreeNode*root=new TreeNode(i);
                    root->left=lefttree[j];
                    root->right=righttree[k];
                    ret.push_back(root);
                }
            }
            
        }
        dp[start-1][end-1]=ret;
    }

   

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        vector<vector<vector<TreeNode*>>> dp(n,vector<vector<TreeNode*>>(n));
        helper(1,n,ret,dp);
        return ret;
    }
};