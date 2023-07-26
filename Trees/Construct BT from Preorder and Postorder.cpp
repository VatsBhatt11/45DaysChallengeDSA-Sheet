class Solution {
public:
    TreeNode* f(vector<int>preorder,int preStart,int preEnd,vector<int>postorder,int postStart,int postEnd)
    {
        if(preStart>preEnd)
            return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        if(preStart==preEnd)
            return root;
        int postInd=postStart;
        while(postorder[postInd]!=preorder[preStart+1])
            postInd++;
        int l=postInd-postStart+1;
        root->left=f(preorder,preStart+1,preStart+l,postorder,postStart,postInd);
        root->right=f(preorder,preStart+l+1,preEnd,postorder,postInd+1,postEnd-1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return f(preorder,0,preorder.size()-1,postorder,0,preorder.size()-1);
    }
};