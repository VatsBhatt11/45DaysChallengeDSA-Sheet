class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n),right(n);
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            if(s.empty())
                left[i]=0;
            else
                left[i]=s.top()+1;
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()]>heights[i])
                s.pop();
            if(s.empty())
                right[i]=n-1;
            else
                right[i]=s.top()-1;
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,heights[i]*(right[i]-left[i]+1));
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0,n=matrix.size(),m=matrix[0].size();
        vector<int>h(m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                    h[j]++;
                else
                    h[j]=0;
            }
            ans=max(ans,largestRectangleArea(h));
        }
        return ans;
    }
};