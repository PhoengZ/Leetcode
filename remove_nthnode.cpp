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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num_node = 0;
        ListNode dummy_1(0);
        ListNode dummy_2(0);
        ListNode * cur = &dummy_2;
        ListNode * rou_2 = &dummy_1;
        ListNode * rou = &dummy_1;
        while (head!= nullptr){
            num_node++;
            rou->next = head;
            head = head->next;
            rou = rou->next;
        }
        int cou = num_node-(n-1);
        num_node = 0;
        rou_2 = rou_2->next;
        while (rou_2 != nullptr){
            num_node++;
            if (cou != num_node){
                cur->next = rou_2;
                cur = cur->next;
            }
            rou_2 = rou_2->next;
        }
        cur->next = nullptr;
        head = dummy_2.next;
        return head;
    }
};