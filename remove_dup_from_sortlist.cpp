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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode * current  = &dummy;
        int check = 101;
        while (head != nullptr){
            if (check != head->val){
                ListNode * get_in = new ListNode(head->val);
                current->next = get_in;
                current = current->next;
                check = head->val;
            }
            head = head->next;
            
        }
        return dummy.next;
    }
};