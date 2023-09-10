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
    int recursion(TreeNode * current){
        int left = 0, right = 0;
        
        if (current -> left != nullptr){
            left++;
            left += recursion(current -> left);
        }
        if (current -> right != nullptr){
            right++;
            right += recursion(current -> right);
        }
            
        if (right - left > 1 || left - right > 1) return 15000;
        else return (left < right ? right : left) ;
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        else if (recursion(root) > 10000 )return false;
        
        return true;
    }
};