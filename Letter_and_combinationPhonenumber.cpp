class Solution {
public:
    vector<string> letterCombinations(string digits) {
        queue<string> q;
        vector <string> vp;
        for (int i = 0;i<digits.length();i++){
            if (i == 0){
                if (digits[i] == '2'){
                    q.push("a");
                    q.push("b");
                    q.push("c");
                }else if (digits[i] == '3'){
                    q.push("d");
                    q.push("e");
                    q.push("f");
                }else if (digits[i] == '4'){
                    q.push("g");
                    q.push("h");
                    q.push("i");
                }else if (digits[i] == '5'){
                    q.push("j");
                    q.push("k");
                    q.push("l");
                }else if (digits[i] == '6'){
                    q.push("m");
                    q.push("n");
                    q.push("o");
                }else if (digits[i] == '7'){
                    q.push("p");
                    q.push("q");
                    q.push("r");
                    q.push("s");
                }else if (digits[i] == '8'){
                    q.push("t");
                    q.push("u");
                    q.push("v");
                }else{
                    q.push("w");
                    q.push("x");
                    q.push("y");
                    q.push("z");
                }
                if (digits.length() == 1){
                    while (!q.empty()){
                        vp.push_back(q.front());
                        q.pop();
                    }
                }
            }else{
                queue<string> qt;
                while (!q.empty()){
                    string a = q.front();
                    if (digits[i] == '2'){
                        qt.push(a+"a");
                        qt.push(a+"b");
                        qt.push(a+"c");
                    }else if (digits[i] == '3'){
                        qt.push(a+"d");
                        qt.push(a+"e");
                        qt.push(a+"f");
                    }else if (digits[i] == '4'){
                        qt.push(a+"g");
                        qt.push(a+"h");
                        qt.push(a+"i");
                    }else if (digits[i] == '5'){
                        qt.push(a+"j");
                        qt.push(a+"k");
                        qt.push(a+"l");
                    }else if (digits[i] == '6'){
                        qt.push(a+"m");
                        qt.push(a+"n");
                        qt.push(a+"o");
                    }else if (digits[i] == '7'){
                        qt.push(a+"p");
                        qt.push(a+"q");
                        qt.push(a+"r");
                        qt.push(a+"s");
                    }else if (digits[i] == '8'){
                        qt.push(a+"t");
                        qt.push(a+"u");
                        qt.push(a+"v");
                    }else{
                        qt.push(a+"w");
                        qt.push(a+"x");
                        qt.push(a+"y");
                        qt.push(a+"z");
                    }
                    q.pop();
                }
                if (i == digits.length()-1){
                    while (!qt.empty()){
                        vp.push_back(qt.front());
                        qt.pop();
                    }
                }else{
                    q = qt;
                }
            }
        }
        return vp;
    }
};