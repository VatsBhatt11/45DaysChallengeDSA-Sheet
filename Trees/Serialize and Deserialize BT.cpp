class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(!temp)
                s+="#,";
            else
                s+=to_string(temp->val)+',';
            if(temp)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;
        stringstream s(data);
        queue<TreeNode*>q;
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
                temp->left=NULL;
            else
            {
                TreeNode* lt=new TreeNode(stoi(str));
                temp->left=lt;
                q.push(lt);
            }
            getline(s,str,',');
            if(str=="#")
                temp->right=NULL;
            else
            {
                TreeNode* rt=new TreeNode(stoi(str));
                temp->right=rt;
                q.push(rt);
            }
        }
        return root;
    }
};