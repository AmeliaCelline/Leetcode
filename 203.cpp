/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return nullptr;
        ListNode * cur = head, * prev = NULL;
        ListNode * newHead = head;
        while (cur != NULL){
            if (cur -> val == val){
                if (prev != NULL){
                    prev -> next = cur -> next;
                }
                else{
                    newHead = cur -> next;
                }
            }
            else{
                prev = cur;
            }
            cur = cur->next;
        }

        return newHead;
    }
};