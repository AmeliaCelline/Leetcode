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
    vector<double> averageOfLevels(TreeNode* root) {
        queue <pair<TreeNode *, int>> forBFS;
        vector<double>answer;
        forBFS.push(make_pair(root, 0));
        int prevLevel = 0;
        long double counter = 0, total = 0;
    
        while(!forBFS.empty()){
            pair <TreeNode*, int> temp = forBFS.front();
            forBFS.pop();

            if (temp.second != prevLevel){
                answer.push_back(total/counter);
                counter = 1;
                total = temp.first->val;
                prevLevel = temp.second;
            }
            else{
                total += temp.first->val;
                counter += 1;
            }

            if (temp.first->left != nullptr){
                forBFS.push(make_pair(temp.first->left, temp.second+1));
            }
            if (temp.first->right != nullptr){
                forBFS.push(make_pair(temp.first->right, temp.second+1));
            }

        }

        answer.push_back(total/counter);

        return answer;

    }
};