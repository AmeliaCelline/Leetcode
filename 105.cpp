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
    unordered_map <int, int> hash;
    
    int index = 0;
    int size;
    TreeNode * divide (vector <int>& preorder, int l, int r){

        if (r-l < 0 || (index+1) >= size || hash[preorder[index+1]] < l || hash[preorder[index+1]] > r) return nullptr;
        
        index++;
        TreeNode * cur = new TreeNode(preorder[index]);
        cur -> left = divide (preorder, l, hash[preorder[index]] - 1);
        cur -> right = divide (preorder, hash[preorder[index]] + 1, r);
        return cur;
        
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        size = inorder.size();
        
        for (int i = 0; i < size; i++ ){
            hash[inorder[i]] = i;
        }
        TreeNode * first = new TreeNode(preorder[0]);
        first -> left = divide (preorder, 0, hash[preorder[0]] - 1);
        first -> right = divide (preorder, hash[preorder[0]] + 1, size-1);
        
        return first;
        
    }
};