//https://leetcode.com/problems/house-robber-iii/
//337. House Robber III
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
    map<TreeNode*, int> m;
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        if (m.find(root)!=m.end()) return m[root];

        int val=0;

        if(root->left!=NULL)
        {   val+=rob(root->left->left)+rob(root->left->right);}

        if(root->right!=NULL)
        { val+=rob(root->right->left)+rob(root->right->right);}

        val=max(val+root->val,rob(root->left)+rob(root->right));
        m[root]=val;
        return val;

    }
};