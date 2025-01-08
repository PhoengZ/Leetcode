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
    void get_vec (vector<int> & vec ,TreeNode * root){
        if (root != NULL){
            get_vec(vec,root->left);
            vec.push_back(root->val);
            get_vec(vec,root->right);
        }
    }    
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> intrav;
        if (root == NULL){
            return intrav;
        }
        get_vec(intrav,root);
        return intrav;
    }
    
    
};