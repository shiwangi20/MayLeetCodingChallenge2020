
// Created on :  20 May, 2020

// Title : Kth Smallest Element in BST

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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode *ans = getKthSmallest(root,count,k);
        return ans->val;
    }
    TreeNode* getKthSmallest(TreeNode* root,int &count,int k){
        if(root == NULL){
            return NULL;
        }
        TreeNode *left = getKthSmallest(root->left,count,k);
        if(left != NULL){
            return left;
        }
        count++;
        if(count == k){
            return root;
        }
        return getKthSmallest(root->right,count,k);
    }
};
