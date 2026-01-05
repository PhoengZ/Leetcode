class Solution {
public:
    int numSquares(int n) {
        vector<int>v(n+1,1000);
        v[0] = 0;
        for (int i = 1;i<=n;i++){
            for (int j = 1;j<=100 && j*j <= i;j++){
                v[i] = min(v[i-(j*j)] + 1, v[i]);
            }
        }
        return v[n];
    }
};