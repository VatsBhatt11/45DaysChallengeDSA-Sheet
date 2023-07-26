class Solution {
public:
    int numTrees(int n) {
        vector<int>ans(n+1,1);
        for(int i=2;i<=n;i++)
        {
            int total=0;
            for(int j=1;j<=i;j++)
            {
                int left=j-1;
                int right=i-j;
                total+=ans[left]*ans[right];
            }
            ans[i]=total;
        }
        return ans[n];
    }
};