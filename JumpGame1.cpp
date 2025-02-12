#include <iostream>
#include <vector>
using namespace std;

bool f(int n, int target, vector<int>&v, vector<int>&table){
    if (n > target)return false;
    if (n == target)return true;
    if (table[n] != 0)return table[n] == 1 ?true:false;
    bool m = false;
    for (int i = 1;i<=v[n];i++){
        m = m || f(n+i,target,v,table);
        if (m)break;
    }
    table[n] = m;
    return m;
}

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    vector<int>table(n);
    for (int i =0;i<n;i++)cin >> v[i];
    bool ans = f(0,n-1,v,table);
    if (ans)cout << "TRUE";
    else cout << "FALSE";
    return 0;
}