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
    int DFS(TreeNode * temp){
        if (temp == nullptr) return 0;
        
        int len_left = 1, len_right = 1;
        len_left += DFS(temp -> left);
        len_right += DFS (temp -> right);
        
        return max(len_left, len_right);
    }
    
    
    int maxDepth(TreeNode* root) {
        return DFS(root);

    }
};