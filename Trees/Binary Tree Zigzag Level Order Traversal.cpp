class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<TreeNode*>q;
        bool flag=true;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>v(n);
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                int ind;
                if(flag)
                    ind=i;
                else
                    ind=n-i-1;
                v[ind]=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            flag=!flag;
            ans.push_back(v);
        }
        return ans;
    }
};