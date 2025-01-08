#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
//use brute force
int main(){
    int n;
    cin>>n;
    vector <string> v;
    v.push_back("(");
    int front_index;
    int dum = 0;
    for (int i = 0;i<2*n;i++){
        if (i == (2*n)-2){
            front_index = v.size();
        }
        int size = v.size();
        for (int j = dum;j<size;j++){
            v.push_back(v[j]+"(");
            v.push_back(v[j]+")");
        }
        dum = size;
    }
    vector <string> vp;
    for (int i = front_index;i<v.size();i++){
        stack <char> st;
        bool check = true;
        for (char c:v[i]){
            if (c == '(')st.push(c);
            else{
                if (st.empty()){
                    check = false;
                    break;
                }
                st.pop();

            }
        }
        if (st.empty() && check)vp.push_back(v[i]);
    }
    for (auto & e:vp)cout << e << " ";
    return 0;
}

