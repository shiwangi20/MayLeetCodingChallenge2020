
// Created On : 24 May, 2020

// Title : Construct BST from Preorder Traversal

// Author : Shiwangi Garg

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if(n == 0){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        if(n == 1){
            return root;
        }
        int val = preorder[0];
        vector<int> left;
        vector<int> right;
        int i = 1;
        for(;i < n;i++){
            if(preorder[i] < val){
                left.push_back(preorder[i]);
            }else{
                break;
            }
        }
        for(;i<n;i++){
            right.push_back(preorder[i]);
        }
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        return root;
    }
};
