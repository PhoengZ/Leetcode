#include <iostream>
#include <vector>
using namespace std;

int f(int n, int target, vector<int>&v, vector<int>&table){
    if (n > target)return 1;
    if (n == target)return 0;
    if (table[n] != 0)return table[n];
    int m = 10000;
    for (int i = 1;i<=v[n];i++){
        m = min(m,f(n+i,target,v,table) + 1);
    }
    table[n] = m;
    return table[n];
}

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    vector<int>table(n);
    for (int i =0;i<n;i++)cin >> v[i];
    int ans = f(0,n-1,v,table);
    cout << ans;
    return 0;
}