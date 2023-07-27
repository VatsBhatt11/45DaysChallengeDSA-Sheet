class Solution
{
    public:
    int f(int n,int x,int y,int z,vector<int>&dp)
    {
        if(n==0)
            return 0;
        if(n<0)
            return INT_MIN;
        if(dp[n]!=-1)
            return dp[n];
        int a=f(n-x,x,y,z,dp)+1;
        int b=f(n-y,x,y,z,dp)+1;
        int c=f(n-z,x,y,z,dp)+1;
        return dp[n]=max(a,max(b,c));
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        /*vector<int>dp(n+1,-1);
        int ans=f(n,x,y,z,dp);
        return max(0,ans);*/
        vector<int>dp(n+1,INT_MIN);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            if(i>=x)
                dp[i]=max(dp[i],dp[i-x]+1);
            if(i>=y)
                dp[i]=max(dp[i],dp[i-y]+1);
            if(i>=z)
                dp[i]=max(dp[i],dp[i-z]+1);
        }
        return max(0,dp[n]);
    }
};