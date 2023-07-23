class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q)
            return root;
        TreeNode* lf=lowestCommonAncestor(root->left,p,q);
        TreeNode* rf=lowestCommonAncestor(root->right,p,q);
        if(!lf)
            return rf;
        if(!rf)
            return lf;
        return root;
    }
};