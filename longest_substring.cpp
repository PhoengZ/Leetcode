
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned int len = 0;
        for (unsigned int i = 0;i<s.length();i++){
            stringstream ss;
            ss << s[i];
            string check = ss.str();
            for (unsigned int j = i+1;j<s.length();j++){
                if (check.find(s[j]) == string::npos){
                    check+= s[j];
                }
                else{
                    break;
                }  
            }
        if (check.length() >len){len = check.length();}
        check = "";    
        }
        return len;
    }
};