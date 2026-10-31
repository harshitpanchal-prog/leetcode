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
    long SUM=0;
    long maxP=0;
    int maxProduct(TreeNode* root) {
        if(!root){
            return 0;
        }
        maxP=0;
        SUM=totalSum(root);
        find(root);
        return maxP%(1000000007);
    }
    int totalSum(TreeNode*root){
        if(!root){
            return 0;
        }
        int leftSubTreeSum=totalSum(root->left);
        int rightSubTreeSum=totalSum(root->right);
        int sum = root->val + leftSubTreeSum + rightSubTreeSum;
        return sum;
    }
    int find(TreeNode*root){
        if(!root){
            return 0;
        }
        int leftSum=find(root->left);
        int rightSum=find(root->right);
        long SubTreeSum=root->val + leftSum + rightSum;
        long remainingSubTreeSum = SUM-SubTreeSum;
        maxP=max(maxP,SubTreeSum*remainingSubTreeSum);
        return SubTreeSum;
    }
};