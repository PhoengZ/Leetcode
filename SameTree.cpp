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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> vec_1;
        vector<int> vec_2;
        get_vec(vec_1,p);
        get_vec(vec_2,q);
        if (vec_1.size() != vec_2.size()){return false;}
        for (int i = 0;i<vec_1.size();i++){
            if (vec_1[i] != vec_2[i]){return false;}
        }
        return true;
    }
    void get_vec(vector<int> & vec,TreeNode * root){
        if (root!= NULL){
            vec.push_back(root->val);
            get_vec(vec,root->left);
            get_vec(vec,root->right);
        }
        else{vec.push_back(10001);}
    }
};