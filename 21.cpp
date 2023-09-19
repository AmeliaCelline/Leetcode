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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //new answer
        if (list1 == nullptr) return list2;
        else if (list2 ==nullptr) return list1;

        ListNode obj = ListNode();
        ListNode * temp = &obj;
        ListNode * temp2 = temp;

        while (list1 != nullptr && list2 != nullptr){
            if (list1 -> val <= list2 -> val){
                temp -> next = list1;
                list1 = list1 ->next;
            }
            else{
                temp -> next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1 != nullptr) temp->next= list1;
        else temp->next = list2;

        
        return temp2 -> next;
    }    


    //  old answer:
    //     ListNode * temp = nullptr;
    //     ListNode * temp2 = nullptr;
    //     ListNode * answer_head = nullptr;
        
    //     while (list1 != nullptr && list2 != nullptr){
                
    //         if(list1->val <= list2->val) {
    //             temp = new ListNode(list1->val);
    //             list1 = list1 -> next;
    //         }
    //         else {
    //             temp = new ListNode(list2->val);
    //             list2 = list2 -> next;
    //         }
            
            
    //         if (temp2 == nullptr){
    //             temp2 = temp;
    //             answer_head = temp2;
    //             continue;
    //         }
            
    //         temp2->next = temp;
    //         temp2 = temp2-> next;
            
      
    //     }
            
    //     while (list1 != nullptr){
    //         temp = new ListNode(list1->val);
    //         list1 = list1->next;
            
    //         if (temp2 == nullptr){
    //             temp2 = temp;
    //             answer_head = temp2;
    //             continue;
    //         }
            
    //         temp2->next = temp;
    //         temp2 = temp2-> next;
            
           
    //     }
        
    //     while (list2 != nullptr){
    //         temp = new ListNode(list2->val);
    //         list2 = list2->next;
            
    //         if (temp2 == nullptr){
    //             temp2 = temp;
    //             answer_head = temp2;
    //             continue;
    //         }
            
    //         temp2->next = temp;
    //         temp2 = temp2-> next;
            

    //     }
    //     return answer_head;
    // }
};