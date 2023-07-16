class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int>r,c;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    r[i]=1;
                    c[j]=1;
                }
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(r[i] || c[j])
                matrix[i][j]=0;
            }
        }
    }
};