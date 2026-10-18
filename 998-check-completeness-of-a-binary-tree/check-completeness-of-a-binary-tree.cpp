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
    int count_nodes(TreeNode*root){
        if(!root)
            return 0;
        return 1+count_nodes(root->left)+count_nodes(root->right);
    }

    bool dfs(TreeNode*root ,int i ,int total_nodes){
        if(!root){
            return true;
        }
        if(i>total_nodes){
            return false;
        }
        return dfs(root->left,i*2,total_nodes )&& dfs( root->right,i*2+1,total_nodes);
    }

    bool isCompleteTree(TreeNode* root) {
        int total_nodes=count_nodes(root);
        int i=1;
        return dfs(root,i,total_nodes);
    }
};