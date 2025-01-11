#include <iostream>
#include <vector>

using namespace std;
int romanToInt(string k) {
    string s = "";
    int value = 0;
    vector <pair<string,int>> vt = {{"CM",900},{"CD",400},{"XC",90},{"XL",40},{"IX",9},{"IV",4}};
    vector <pair<char,int>> vp = {{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
    for (auto &e:k){
        s+= e;
        bool check = false;
        if (s.length() == 2){
            for (auto &i:vt){
                if (i.first == s){
                    value += i.second;
                    check = true;
                    s = "";
                    break;
                }
            }
            if (!check){
                for (auto &i:vp){
                    if (i.first == s[0]){
                        value+= i.second;
                        break;
                    }
                }
                s = e;
            }
        }
    }
    if (s.length() != 0){
        for (auto & e:vp){
            if (e.first == s[0]){
                value+=e.second;
                break;
            }
        }
    }
    return value;
}
int main(){
    string e;
    cin>>e;
    cout << romanToInt(e);
    return 0;
}
