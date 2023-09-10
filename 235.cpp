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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * small, *big;
        if (p->val < q->val){
            small = p;
            big = q;
        }
        else{
            small = q;
            big = p;
        }
        
        
        while(root != NULL){
            if (root == small || root == big){
                return root;
            }
            else if (big->val < root->val){
                root = root -> left;
            }
            else if (small -> val > root -> val){
                root = root->right;
            }
            else return root;
        
        
        }
        return root;
        
    }
};