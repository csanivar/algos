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
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
       /*
       1-2-3-4-5-6
       1-2-3-4 6-5-4
       1-6-2-5-3-4
       */
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* tmp;
        while(curr != NULL) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        
        ListNode* first = head;
        ListNode* second = prev;
        while(second->next != NULL) {
            tmp = first->next;
            first->next = second;
            first = tmp;
            
            tmp = second->next;
            second->next = first;
            second = tmp;
        }
    }
};
