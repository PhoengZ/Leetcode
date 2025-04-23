#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve(vector<vector<char>>& board) {
    vector<vector<bool>>sel(board.size(),vector<bool>(board[0].size()));
    vector<vector<int>> v  = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int i = 0;i<board.size();i++){
        for (int j = 0;j<board[0].size();j++){
            // cout << "I,J: " << i << " ," << j <<" sel[2][3]: "<<sel[2][3] << endl;
            if (board[i][j] == 'X' || sel[i][j]){
                sel[i][j] = true;
                continue;
            }
            stack<pair<int,int>>s;
            s.push({i,j});
            sel[i][j] = true;
            bool check = true;
            if (i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() -1)check = false;
            while(!s.empty()){
                pair<int,int> p = s.top();
                s.pop();
                for (int i = 0;i<4;i++){
                    int row = p.first + v[i][0];
                    int col = p.second + v[i][1];
                    if (row < 0 || row == board.size() || col < 0 || col == board[0].size()){
                        continue;
                    }
                    if (row == 0 || row == board.size() - 1 || col == 0 || col == board[0].size() - 1){
                        if (board[row][col] == '0')check = false;
                    }
                    if (board[row][col] != 'X' && !sel[row][col]){
                        sel[row][col] = true;
                        s.push({row,col});
                    }
                }
            }
            if (check){
                s.push({i,j});
                while(!s.empty()){
                    pair<int,int> p = s.top();
                    board[p.first][p.second] = 'X';
                    s.pop();
                    for (int i = 0;i<4;i++){
                        int row = p.first + v[i][0];
                        int col = p.second + v[i][1];
                        if (row == 0 || row == board.size() || col == 0 || col == board[0].size()){
                            continue;
                        }
                        if (board[row][col] != 'X'){
                            s.push({row,col});
                        }
                    }
                }
            }
        }
    }
}


int main(){
    vector<vector<char>>v(5,vector<char>(5));
    for (int i = 0;i<5;i++){
        for (int j = 0;j<5;j++){
            cin >> v[i][j];
        }
    }
    solve(v);
    for (int i = 0;i<v.size();i++){
        for (int j = 0;j<v[0].size();j++)cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}