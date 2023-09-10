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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int> > answer;
        if (root == nullptr) return answer;
        
        vector<int> level;
        
        queue <TreeNode * > q;
        q.push(root);
        
        TreeNode * temp;
        int counter = 1;
        int counter2 = 0;
        
        while (!q.empty()){
            temp = q.front();
            q.pop();
            
            level.push_back(temp->val);
            counter--;
            if (temp->left != nullptr) {
                q.push(temp->left);
                counter2 += 1;
                
            }
            if (temp -> right != nullptr){
                q.push(temp->right);
                counter2 += 1;
            } 
            if (counter == 0){
                counter = counter2;
                counter2 = 0;
                
                answer.push_back(level);
                level.clear();
                
            }
            
            
        }
        return answer;
    }
};