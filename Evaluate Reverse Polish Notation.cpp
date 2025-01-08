#include <string>
#include <stack>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for (string e:tokens){
            if (e!= "+" && e!= "-" && e!= "/" && e!="*"){
                int x = stoi(e);
                st.push(x);
            }else{
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int result;
                if (e == "+"){result = a+b;
                }else if (e == "-"){result = a-b;
                }else if(e == "*"){result = a*b;
                }else{result = a/b;}
                st.push(result);
            }
        }
        return st.top();
    }
};