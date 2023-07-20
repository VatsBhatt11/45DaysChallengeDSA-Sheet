class Solution {
public:
    bool help(TreeNode* left,TreeNode* right)
    {
        if(!left || !right)
            return left==right;
        if(left->val!=right->val)
            return false;
        return (help(left->left,right->right) && help(left->right,right->left));
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return help(root->left,root->right);
    }
};