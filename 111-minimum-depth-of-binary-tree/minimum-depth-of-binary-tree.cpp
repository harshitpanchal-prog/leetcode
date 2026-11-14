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
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int depth=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left == NULL && temp->right == NULL){
                    return depth;
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
                if(temp->left != NULL){
                    q.push(temp->left);
                }
            }
            depth++;
        }
        return -1;
    }
};