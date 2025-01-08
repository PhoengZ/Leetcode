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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        ListNode * cur = &dummy;
        dummy.next = head;
        while (head != NULL && head->next != NULL){
            ListNode *first = head;
            ListNode *second = head->next;
            cur->next = second;
            first->next = second->next;
            second->next = first;

        // Move cur to the end of the swapped pair
            cur = first;

        // Move head to the start of the next pair
            head = first->next;
        }
        if (head!= NULL){cur->next = head;}
        else{
            cur->next = NULL;
        }
        return dummy.next;   
    }
};