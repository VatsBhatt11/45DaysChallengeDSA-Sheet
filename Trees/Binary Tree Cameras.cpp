lass Solution {
public:
    int dfs(TreeNode* root,int &sum)
    {
        if(!root)
            return 1;
        int lt=dfs(root->left,sum);
        int rt=dfs(root->right,sum);
        if(lt==0 || rt==0)
        {
            sum++;
            return 2;
        }
        else if(lt==2 || rt==2)
            return 1;
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        int sum=0;
        if(dfs(root,sum)==0)
            sum++;
        return sum;
    }
};