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
        ListNode test(0); // Dummy node to simplify the merging process
        ListNode* current = &test; // Pointer to the end of the merged list

    // Iterate while both lists have nodes
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1; // Append list1 node
                list1 = list1->next; // Move to the next node in list1
            } else {
                current->next = list2; // Append list2 node
                list2 = list2->next; // Move to the next node in list2
            }
            current = current->next; // Move the tail to the newly added node
        }

    // Attach the remaining nodes from either list1 or list2
        if (list1 != nullptr) {
            current->next = list1;
        } else if (list2 != nullptr) {
            current->next = list2;
        }
        return test.next;
    }    
    
};