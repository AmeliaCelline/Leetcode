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

        //basically slow and fast pointer
        ListNode * fast = head, * slow = head;
        while (fast != NULL){
            if (fast -> next != NULL){
                fast = fast -> next -> next; 
                slow = slow -> next;
            } 
            else return false;
            if (fast == slow) return true;
        }
        return false;



        // while (head != NULL){
        //     if (head -> val == 100001){
        //         return true;
        //     }
        //     else head -> val = 100001;
            
        //     head = head->next;
        // }
        // return false;
    }
};