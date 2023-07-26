vector<int>dp(46,-1);
class Solution {
public:
    int climbStairs(int n) {
        dp[0]=dp[1]=1;
        if(dp[n]!=-1)
        return dp[n];
        return (dp[n]=climbStairs(n-1) + climbStairs(n-2));
    }
};