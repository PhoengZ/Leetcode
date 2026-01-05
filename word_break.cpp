class Solution {
public:
    
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> w;
        for (auto &e : wordDict)
        {
            w.insert(e);
        }
        int n = s.length();
        vector<int>check(n+1,-1);
        check[0] = 1;
        for (int i = 1;i<=n;i++){
            for (int j = 1;j<=i;j++){
                string e = s.substr(j-1,i-j + 1);
                if (w.count(e) && check[j-1]){
                    check[i] = 1;
                }
            }
            if (check[i] == -1){
                check[i] = 0;
            }
        }
        return check[n];
    }
};