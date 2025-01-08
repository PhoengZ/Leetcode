#include <algorithm>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()){
            return "";
        }
        int i = 0;
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[strs.size()-1];
        while (i<first.length() && i<last.length()){
            if (first[i] == last[i]){
                i++;
                
            }
            else{break;}
        }
        string sub = first.substr(0,i);
        return sub;
    }
};