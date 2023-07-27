class Solution {
public:
    int f(vector<string>& strs, int m, int n,int i,vector<vector<vector<int>>>&dp)
    {
        if(i==strs.size() || m<0 || n<0)
            return 0;
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        int one=count(strs[i].begin(),strs[i].end(),'1');
        int zero=strs[i].size()-one;
        int notTake=f(strs,m,n,i+1,dp);
        int take=0;
        if(m>=zero && n>=one)
            take=1+f(strs,m-zero,n-one,i+1,dp);
        return dp[i][m][n]=max(notTake,take);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        /*vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return f(strs,m,n,0,dp);*/
        int sz=strs.size();
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i=sz-1;i>=0;i--)
        {
            int one=count(strs[i].begin(),strs[i].end(),'1');
            int zero=strs[i].size()-one;
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    int notTake=dp[i+1][j][k];
                    int take=0;
                    if(j>=zero && k>=one)
                        take=1+dp[i+1][j-zero][k-one];
                    dp[i][j][k]=max(notTake,take);
                }
            }
        }
        return dp[0][m][n];
    }
};