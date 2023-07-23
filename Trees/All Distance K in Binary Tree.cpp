class Solution {
public:
    void makeParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&pm)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left)
            {
                pm[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                pm[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>pm;
        makeParents(root,pm);
        int level=0;
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool>v;
        v[target]=true;
        while(!q.empty())
        {
            if(level++==k)
                break;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !v[temp->left])
                {
                    v[temp->left]=true;
                    q.push(temp->left);
                }
                if(temp->right && !v[temp->right])
                {
                    v[temp->right]=true;
                    q.push(temp->right);
                }
                if(pm[temp] && !v[pm[temp]])
                {
                    v[pm[temp]]=true;
                    q.push(pm[temp]);
                }
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};