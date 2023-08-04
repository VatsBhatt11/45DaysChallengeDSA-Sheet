class Solution {
public:
    TreeNode* f(int &i,int bound,vector<int>&v)
    {
        if(i==v.size() || v[i]>bound)
            return NULL;
        TreeNode* root=new TreeNode(v[i++]);
        root->left=f(i,root->val,v);
        root->right=f(i,bound,v);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return f(i,INT_MAX,preorder);
    }
};