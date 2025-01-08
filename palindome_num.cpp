#include <string>
class Solution {
public:
    bool isPalindrome(int x) {
        string X_check =  to_string(x);
        string out;
        for (int i = X_check.length()-1;i>=0;i--){
            out+= X_check[i];
        }
        if (out == X_check){return true;}
        return false;
    }
};