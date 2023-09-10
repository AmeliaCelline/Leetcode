/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        while (head != NULL){
            if (head -> val == 100001){
                return true;
            }
            else head -> val = 100001;
            
            head = head->next;
        }
        return false;
    }
};