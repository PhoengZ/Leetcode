#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<bool>> v(n);
    for (int i =0;i<n;i++){
        vector<bool>b(n);
        v[i] = b;
    }
    for (int i = 0;i<n;i++){
        v[i][i] = true;
    }
    int start = 0;
    int mlen = 0;
    for (int i = 1;i<n;i++){
        if (s[i] == s[i-1]){
            v[i][i-1] = true;
            mlen = i;
            start = i-1;
        }
    }
    for (int i = 3;i<=n;i++){
        for (int j = 0;j<=n-i;j++){
            if (s[j] == s[j+i-1] && v[j+1][j+1]){
                v[i-1][j] = true;
                if (i - j > mlen-start){
                    start = j;
                    mlen = j+i-1;
                }
            }
        }
    }
    string e = "";
    for (int i = start;i<=mlen;i++)e+= s[i];
    cout << e;
    return 0;
}