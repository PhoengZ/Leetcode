#include <iostream>
#include <vector>

using namespace std;
void my_recur(vector<vector<int>>&candidate,vector<int>&st,int target,int total,vector<int>&select,int start){
    for (int i = start;i<select.size();i++){
        int e = select[i];
        if (total+e < target){
            st.push_back(e);
            my_recur(candidate,st,target,total+e,select,i);
            st.pop_back();
        }else if (total + e == target){
            st.push_back(e);
            candidate.push_back(st);
            st.pop_back();
        }
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
    vector <vector<int>> vp = combinationSum(v,t);
    for (int i = 0;i<vp.size();i++){
        cout << "size index: " << vp[i].size()<<endl;
        for (auto&e:vp[i])cout << e << " ";
        cout <<endl;
    }
    return 0;
}