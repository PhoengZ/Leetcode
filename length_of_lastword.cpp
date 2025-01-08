#include <stack>
class Solution {
public:
    int lengthOfLastWord(string s) {
        stack <string> get_str;
        string check;
        bool get_check =false;
        for (int i =0;i<s.length()-1;i++){
            if (s[i] != ' '){
                check+= s[i];
            }
            else{
                if (check!= ""){
                    get_str.push(check);
                }
                check = ""; 
            }
        }
        if (s[s.length()-1] != ' '){
            check += s[s.length()-1];
        } 
        if (check.length() != 0){
            get_str.push(check);
        }
        return get_str.top().length();
    }
};