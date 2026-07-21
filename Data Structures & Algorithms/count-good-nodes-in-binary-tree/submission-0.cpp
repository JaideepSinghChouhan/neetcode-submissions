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
    void dfs(TreeNode *root,int &cnt,int max){
        if(root==NULL) return ;
        if(root->val>=max){
            max=root->val;
            cnt++;
        }
        if(root->left) dfs(root->left,cnt,max);
        if(root->right) dfs(root->right,cnt,max);
    }
    int goodNodes(TreeNode* root) {
        int cnt=0;
        int max=INT_MIN;
        dfs(root,cnt,max);
        return cnt;
    }
};
