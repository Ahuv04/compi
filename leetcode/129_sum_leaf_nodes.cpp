//https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=daily-question&envId=2024-04-16
//129. Sum Root to Leaf Numbers
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
#include <cmath>
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans=0;
        if(root==NULL)
        {return 0;}
        else if(root->left==NULL && root->right==NULL)
        {return root->val;}
        else{
            if(root->left!=NULL)
            {   ans+=sumx(root->left,root->val);}
            if(root->right!=NULL)
            {   ans+=sumx(root->right, root->val);}
        }
        return ans;
    }

    int sumx(TreeNode* root, int x){
        int ans=0;
        if(root==NULL)
        {return x;}
        else if(root->left==NULL && root->right==NULL)
        {return x*10+root->val;}
        else{
            if(root->left!=NULL)
            {   ans+=sumx(root->left,x*10+root->val);}
            if(root->right!=NULL)
            {   ans+=sumx(root->right, x*10+root->val);}
        }
        return ans;
    }
};
