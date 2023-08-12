class Solution {
public:
    void helper(int pos,int n,vector<bool>&visited,int &ans)
    {
        if(pos>n)
        {
            ans++;
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(!visited[i] && (pos%i==0 || i%pos==0))
            {
                visited[i]=true;
                helper(pos+1,n,visited,ans);
                visited[i]=false;
            }
        }
    }

    int countArrangement(int n) {
        vector<bool>visited(n+1);
        int ans=0;
        helper(1,n,visited,ans);
        return ans;
    }
};