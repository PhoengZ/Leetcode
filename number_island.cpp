class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visit(m, vector<bool>(n,false));
        vector<pair<int,int>>lands;
        stack<pair<int,int>>s;
        for (int i = 0;i<m;i++){
            for (int j = 0;j<n;j++){
                if (grid[i][j] == '1'){
                    pair<int,int> p = {i,j};
                    lands.push_back(p);
                }
            }
        }
        int result = 0;
        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,-1},{0,1}};
        for (auto &e:lands){
            if (visit[e.first][e.second]){
                continue;
            }
            result++;
            s.push(e);
            while(!s.empty()){
                pair<int,int> p = s.top();
                s.pop();
                for (auto &t:dir){
                    int row = p.first + t.first;
                    int col = p.second + t.second;
                    if(row< 0 ||row >= m || col < 0 || col >= n){
                        continue;
                    }
                    if (visit[row][col]){
                        continue;
                    }
                    if (grid[row][col] == '0')continue;
                    visit[row][col] = true;
                    s.push({row,col});
                }
            }
        }
        return result;
    }
};