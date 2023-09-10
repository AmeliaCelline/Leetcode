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

    int found_q = 0;
    int found_p = 0;
    
    int level1, level2;
    
    unordered_map <TreeNode*, TreeNode*> parent;
    
    void DFS(TreeNode * temp, TreeNode *p, TreeNode* q, int level){
        if (temp == p){
            found_p = 1;
            level1 = level;
            if (found_q == 1) return;
        }
        else if (temp == q){
            found_q = 1;
            level2 = level;
            if (found_p == 1) return;
        }
        
        if (temp -> left != NULL){
            parent[temp->left] = temp;
            DFS(temp->left, p, q, level+1);
        }
        if (temp -> right != NULL){
            parent[temp->right] = temp;
            DFS(temp->right, p, q, level+1);
        }
        
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parent[root] = NULL;
        if (root -> left != NULL){
            parent[root->left] = root;
            DFS(root, p, q, 1);
        }
        if (root -> right != NULL){
            parent[root->right] = root;
            DFS(root, p, q, 1);
        }
        
        TreeNode * transverse;
        while (level2 > level1){
            q = parent[q];
            level2 --;
        }
        while (level1 > level2){
            p = parent[p];
            level1 --;
        }
        
        while(1){
            if(p != q){
                p = parent[p];
                q = parent[q];
            }
            else break;
        }
        
        return p;
    }
};