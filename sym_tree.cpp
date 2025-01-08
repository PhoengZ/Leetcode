/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        vector<int> vec_1;
        vector<int> vec_2;
        int check = 101;
        get_vec_left(vec_1,root->left,check);
        check = 101;
        get_vec_right(vec_2,root->right,check);
        if (vec_1.size() != vec_2.size()){return false;}
        cout << vec_1.size() << " and " << vec_2.size()<<endl;
        for (int i = 0;i<vec_1.size();i++){
            cout << "root left = "<<vec_1[i] << "root right = " << vec_2[i] << endl;
            if (vec_1[i] != vec_2[i]){return false;}
        }
        return true;
    }
    void get_vec_left(vector<int> & vec,TreeNode * root,int & r){
        r++;
        if (root!= NULL){
            get_vec_left(vec,root->left,r);
            vec.push_back(root->val);
            get_vec_left(vec,root->right,r);
        }
        else{vec.push_back(r);}
    }
    void get_vec_right(vector<int> & vec,TreeNode * root ,int & r){
        r++;
        if (root!= NULL){
            get_vec_right(vec,root->right,r);
            vec.push_back(root->val);
            get_vec_right(vec,root->left,r);
        }
        else{vec.push_back(r);}
    }
};