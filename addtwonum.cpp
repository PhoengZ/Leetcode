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

#include <string> 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode * current = &dummy;
        string l_1 = "";
        string l_2 = "";
        while (l1 != nullptr){
            char c = '0' + l1->val;
            l_1 += c;
            l1 = l1->next;
        }
        while (l2!= nullptr){
            char c = '0' + l2->val;
            l_2 += c; 
            l2 = l2->next;
        }
        int len_shorter = l_1.length()>=l_2.length() ? l_2.length():l_1.length();
        int len_longer = l_1.length()>=l_2.length() ? l_1.length():l_2.length();
        string l_1_reverse = "";
        string l_2_reverse = "";
        for (int i = l_1.length()-1;i>=0;i--){
            l_1_reverse += l_1[i];
        }
        for (int i = l_2.length()-1;i>=0;i--){
            l_2_reverse += l_2[i];
        }
        cout << "reverserL_1 = " << l_1_reverse << "reverserL_2 = " << l_2_reverse <<endl;
        int index_run = (len_shorter-1);
        int index_long = (len_longer-1);
        string out = "";
        int plus = 0;
        cout << index_run << ", " << index_long <<endl;
        while (index_run>=0){
            int e_1;
            int e_2;
            if (len_longer == l_1_reverse.length()){
                e_1 = l_1_reverse[index_long] - '0';
                e_2 = l_2_reverse[index_run] - '0';
            }else{
                e_1 = l_1_reverse[index_run] - '0';
                e_2 = l_2_reverse[index_long] - '0';
            }
            
            cout <<"e_1 and e_2 = "<< e_1 <<", "<< e_2<<endl;
            int total = e_1+e_2;
            cout <<"total = "<< total << ", "<<endl;
            if (plus!= 0){
                total+=plus;
            }
            int mod = total%10;
            plus = total/10;
            char c = '0'+mod;
            index_run--;
            index_long--;
            
            out = c+out;
        }
        
        if (l_1.length() == len_longer){
            for (int i = (len_longer-len_shorter)-1;i>=0;i--){
                int e_1 = l_1_reverse[i] - '0';
                if (plus != 0){
                    e_1+=plus;
                }
                plus = e_1/10;
                e_1 = e_1%10;
                char c = '0' + e_1;
                out = c+out;
            }
        }
        
        else{
            for (int i = (len_longer-len_shorter)-1;i>=0;i--){
                int e_2 = l_2_reverse[i] - '0';
                if (plus != 0){
                    e_2+=plus;
                }
                plus = e_2/10;
                e_2 = e_2%10;
                char c = '0' + e_2;
                out = c+out;
            }
        }
        if (plus>0){
            char c = '0' + plus;
            out = c+out;
        }
        cout << out << endl;
        for (int e = out.length()-1;e>=0;e--){
            int num = out[e] -'0';
            ListNode * now = new ListNode(num);
            current->next = now;
            current = current->next;
        }        
        return dummy.next;
    }
};