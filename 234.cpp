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
    bool isPalindrome(ListNode* head) {
        // 1 2 3 4 5 6
        // 1 - > 3 -> 5 -> 6 fast pointer
        // 1 - > 2 -> 3 -> 4 slow pointer
        // NULL <- 1 <- 2 <- 3, 4 -> 5 -> 6 slow pointer is at 4, prev is at 3

        // 1 2 3 4 5
        // 1 -> 3 -> 5 fast
        // 1 -> 3 slow
        // NULL <- 1 prev


        if (head == nullptr) return true;

        ListNode * fast = head, *slow = head;
        ListNode * prev = nullptr;
        
        bool check = true;
        while (fast -> next != nullptr){
            if (fast-> next -> next == nullptr){
              fast = fast -> next;
              check = false;
            }
            else{ 
              fast = fast->next -> next;
            }

            ListNode * temp = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = temp;

        }

        if(check) slow = slow->next;
        ListNode * left = prev;
        ListNode * right = slow;

        while (left != nullptr){
            if (left -> val != right -> val) return false;
            left = left->next;
            right = right ->next;
        }

        return true;

    }
};