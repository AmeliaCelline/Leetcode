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
    vector<int> rightSideView(TreeNode* root) {
        vector <int> answer;
        stack <TreeNode *> storage;
        stack <int> level;
        
        int cur_level = 0, highest_level = -1;
        while (root != nullptr){
            if (cur_level > highest_level){
                answer.push_back(root->val);
                highest_level = cur_level;
            }
                
            
            if (root -> right != nullptr) {
                if (root -> left != nullptr){
                    storage.push(root);
                    level.push(cur_level);
                }
                root = root->right;
            }
            else if (root -> left != nullptr) root = root->left;
            else if (!storage.empty()){
                root = storage.top() -> left;
                cur_level = level.top();
                storage.pop();
                level.pop();

            }
            else{
                root = nullptr;
            }
            cur_level += 1;
        }
        return answer;
        
    }
};