class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>u;
        for (auto &e:strs){
            string t = e;
            sort(e.begin(),e.end());
            u[e].push_back(t);
        }
        vector<vector<string>>sol;
        for (auto &e:u){
            sol.push_back(e.second);
        }
        return sol;
    }
};