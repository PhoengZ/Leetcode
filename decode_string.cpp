class Solution {
public:
    string decodeString(string s) {
        vector<char>n = {'0','1','2','3','4','5','6','7','8','9'};
        string result = "";
        vector<string>last = {""};
        vector<int> k;
        string sn = "";
        int num_bracket = 0;
        for (auto & e:s){
            bool found = false;
            if (e == '['){
                num_bracket++;
                last.push_back("");
                int j = stoi(sn);
                sn = "";
                k.push_back(j);
                continue;
            }
            if (e == ']'){
                string t = "";
                for (int j = 0;j<k[num_bracket-1];j++){
                    t+= last[num_bracket];
                }
                num_bracket--;
                last.pop_back();
                k.pop_back();
                last[num_bracket]+= t;
                continue;
            }
            for (int i = 0;i<10;i++){
                if (n[i] == e){
                    found = true;
                    sn+=e;
                    break;
                }
            }
            if (!found){
                last[num_bracket] += e;
            }

        }
        return last[0];
    }
};