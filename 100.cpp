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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr){
            if (p == nullptr && q == nullptr) return true;
            else return false;
        }
        else{
            if (p -> val == q -> val) {
                bool left = isSameTree(p->left, q -> left);
                bool right = isSameTree(p-> right, q -> right);

                if (left && right) return true;
                else return false;
            }
            else return false;
        }
    }
};