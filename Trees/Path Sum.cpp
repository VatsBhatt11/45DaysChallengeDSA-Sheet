class Solution {
public:
    bool f(TreeNode* root,int sum,int targetSum)
    {
        if(!root)
            return false;
        sum+=root->val;
        if(!root->left && !root->right)
            return (sum==targetSum);
        return (f(root->left,sum,targetSum) || f(root->right,sum,targetSum));
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return f(root,sum,targetSum);
    }
};