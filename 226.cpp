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


//NEW SOLUTION

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode * left = invertTree(root->left);
        TreeNode * right = invertTree(root->right);

        root->right = left;
        root->left = right;

        return root;
    }
};


//OLD SOLUTION:
/*class Solution {
public:
    TreeNode * temp;
    void recursion(TreeNode * n, TreeNode * temp2){
        if (n->left != nullptr){
            //cout << n->left->val << endl;
            temp2->right = new TreeNode(n->left->val);
            
            recursion(n->left, temp2->right);
        }
        if (n->right != nullptr){
            //cout << n->right->val << endl;
            temp2->left = new TreeNode(n->right->val);
            
            recursion(n->right, temp2->left);
            
        }
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        
        temp = new TreeNode(root->val);
        recursion(root, temp);
        
        return temp;
    }
};*/