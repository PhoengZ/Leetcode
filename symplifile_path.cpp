#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack <string> s;
    string output = "";
    string path;
    int state = 0;
    cin >> path;
    for (char &c: path){
        if (state == 0){
            if (c == '.'){
                state = 1;
            }else if (c != '/'){
                output += c;
            }else{
                if (output != ""){
                    s.push(output);
                }
                output = "";
            }
        }else if (state == 1){
            if (c == '.'){
                state = 2;
            }else if (c == '/'){
                if (output != ""){
                    output += '.';
                    s.push(output);
                    output = "";
                }
                state = 0;
            }else{
                output += '.';
                output += c;
                state = 0;
            }
        }else if (state == 2){
            if (c == '.'){
                output += "...";
            }else if (c == '/'){
                if (!s.empty() && output == ""){
                    s.pop();
                }else if (output != ""){
                    output += "..";
                    s.push(output);
                }
                output = "";
            }else{
                output += "..";
                output += c;
            }
            state = 0;
        }
    }
    if (state == 0){
        if (output != ""){
            s.push(output);
        }
    }else if (state == 1){
        if (output != ""){
            output += '.';
            s.push(output);
        }
    }else if (state == 2){
        if (!s.empty() && output == ""){
            s.pop();
        }else if (output != ""){
            output += "..";
            s.push(output);
        }
    }
    output = "";
    while (!s.empty()){
        output = s.top() + "/" + output;
        s.pop();
    }
    if (output.size() > 0){
        output.pop_back();
    }
    cout << "/" << output << endl;
    return 0;
}