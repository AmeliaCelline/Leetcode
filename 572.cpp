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
    bool isSame(TreeNode * cur1, TreeNode * cur2){
        if(cur1 == nullptr && cur2 == nullptr)return true;
        else if (cur1 == nullptr || cur2 ==nullptr) return false;

        if (cur1->val == cur2->val){
            return isSame(cur1 -> left, cur2->left) && isSame(cur1->right, cur2->right);
        }
        return false;

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;
        else if(root -> val == subRoot -> val){
            bool temp =  isSame(root -> left , subRoot ->left) && isSame(root->right, subRoot->right);
            if (temp) return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    

    } 
};