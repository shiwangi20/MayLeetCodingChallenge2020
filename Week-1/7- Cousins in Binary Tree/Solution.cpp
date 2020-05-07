
// Created on : 7 May, 2020

// Title : Cousins in Binary Tree

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
    bool isCousins(TreeNode* root, int x, int y) {
        return ((findLevel(root,x,1) == findLevel(root,y,1)) && (! isSibling(root,x,y)));
    }
    
    int findLevel(TreeNode* root,int num,int level){
        if(root == NULL)
            return 0;
        if(root->val == num)
            return level;
        int l = findLevel(root->left,num,level+1);
        if(l != 0){
            return l;
        }
        return findLevel(root->right,num,level+1);
    }
    
    bool isSibling(TreeNode* root,int x,int y){
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return false;
        }
        if(root->left == NULL){
            return isSibling(root->right,x,y);
        }else if(root->right == NULL){
            return isSibling(root->left,x,y);
        }else return ((root->left->val == x && root->right->val == y) || 
                     (root->left->val == y && root->right->val == x) || 
                     (isSibling(root->left,x,y)) || (isSibling(root->right,x,y)));
    }
        
};
