class Solution {
public:
    int f(int i,int j,int &ans,vector<vector<char>>&matrix,vector<vector<int>>&dp)
    {
        if(i>=matrix.size() || j>=matrix[0].size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down=f(i+1,j,ans,matrix,dp);
        int right=f(i,j+1,ans,matrix,dp);
        int diag=f(i+1,j+1,ans,matrix,dp);
        dp[i][j]=0;
        if(matrix[i][j]=='1')
            dp[i][j]=1+min(diag,min(down,right));
        ans=max(ans,dp[i][j]);
        return dp[i][j];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        f(0,0,ans,matrix,dp);
        return ans*ans;
    }
};