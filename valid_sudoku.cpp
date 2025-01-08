#include <set>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0;i<9;i++){
            for (int j =0;j<9;j++){
                if (board[i][j] != '.'){
                    int s_row = (i/3)*3;
                    int s_col = (j/3)*3;
                    vector<char> vec_col = {board[0][j],board[1][j],board[2][j],board[3][j],board[4][j],board[5][j],board[6][j],board[7][j],board[8][j]};
                    vector<char> vec_three = {board[s_row][s_col],board[s_row+1][s_col],board[s_row+2][s_col],board[s_row][s_col+1],board[s_row+1][s_col+1],board[s_row+2][s_col+1],board[s_row][s_col+2],board[s_row+1][s_col+2],board[s_row+2][s_col+2]};
                    if (!firstRule(board[i])){
                        /*cout << "incorrect the fiirst rule at row " << i << " and col " << j <<endl; 
                        for (int p = 0;p<9;p++){
                            cout << board[i][p] << ", ";
                        }*/
                        return false;
                    }
                    if  (!firstRule(vec_col)){
                        /*cout << "incorrect the second rule at row " << i << " and col " << j <<endl;
                        for (int p = 0;p<9;p++){
                            cout << vec_col[p] << ", ";
                        }*/
                        return false;
                    }
                    if (!firstRule(vec_three)){
                        /*cout << "incorrect the third rule at row " << i << " and col " << j <<endl; 
                        for (int p = 0;p<9;p++){
                            cout << vec_three[p] << ", ";
                        }*/
                        return false;
                    }
                } 
            }
        }
        return true;
    }
    bool firstRule(vector<char> vec){
        set<char> myset;
        for (int i = 0;i<vec.size();i++){
            if (vec[i] != '.'){
                if (myset.find(vec[i]) != myset.end()){
                    return false;
                }
                myset.insert(vec[i]);
            }
        }
        return  true;
    }
};