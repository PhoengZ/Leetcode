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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)return head;
        ListNode * mHeader = head;
        ListNode * temp;
        int size = 0;
        while (mHeader!= NULL){
            if (size == 0)temp = mHeader;
            else{
                temp = temp->next;
            }
            mHeader= mHeader->next;
            size++;
        }
        k%=size;
        if (k == 0)return head;
        temp->next = head;
        mHeader = head;
        for (int i =0;i<size;i++){
            if (i == size - k){
                temp->next = NULL;
                break;
            }else{
                mHeader = mHeader->next;
                temp = temp->next;
            }
        }
        head = mHeader;
        return head;
    }
};