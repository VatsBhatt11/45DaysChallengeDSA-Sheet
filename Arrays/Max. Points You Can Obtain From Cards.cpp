class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int i,ans,sum=0,n=card.size(),j=n-1;
        for(i=0;i<k;i++)
            sum+=card[i];
        i--;
        ans=sum;
        while(k--)
        {
            sum-=card[i--];
            sum+=card[j--];
            ans=max(ans,sum);
        }
        return ans;
    }
};