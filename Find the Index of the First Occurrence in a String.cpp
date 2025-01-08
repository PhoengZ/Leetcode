class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle) == string::npos){
            return -1;
        }
        int index =0;
        for (int i =0;i<=haystack.length()-needle.length();i++){
            string check = haystack.substr(i,needle.length());
            if (check == needle){
                index = i;
                break;
            }
        }
        return index;
    }
};