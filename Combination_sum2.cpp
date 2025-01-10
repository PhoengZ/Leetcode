#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//pass 172/176 testcase
void my_recur(vector<vector<int>>&candidate,vector<int>&st,int target,int total,vector<int>&select,int start){
    for (int i = start;i<select.size();i++){
        int e = select[i];
        if ((st.empty() && i>0 && e == select[i-1] ))continue;
        if (total+e < target){
            st.push_back(e);
            my_recur(candidate,st,target,total+e,select,i+1);
            st.pop_back();
        }else if (total + e == target){
            st.push_back(e);
            auto low = lower_bound(candidate.begin(),candidate.end(),st);
            if (candidate.empty() || st != *low)candidate.push_back(st);
            st.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<int> st;
    vector<vector<int>> vp;
    my_recur(vp,st,target,0,candidates,0);
    return vp;
}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for (int i =0;i<n;i++)cin>>v[i];
    vector <vector<int>> vp = combinationSum2(v,t);
    for (int i = 0;i<vp.size();i++){
        cout << "size index: " << vp[i].size()<<endl;
        for (auto&e:vp[i])cout << e << " ";
        cout <<endl;
    }
    return 0;
}