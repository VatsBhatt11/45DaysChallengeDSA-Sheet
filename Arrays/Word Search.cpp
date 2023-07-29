class Solution {
public:
    bool f(int i,int j,int ind,vector<vector<int>>&vis,vector<vector<char>>& board, string word)
    {
        if(ind==word.size())
            return true;
        if(i>=board.size() || j>=board[0].size() || word[ind]!=board[i][j] || vis[i][j])
            return false;
        vis[i][j]=1;
        if(f(i+1,j,ind+1,vis,board,word) || 
           f(i,j+1,ind+1,vis,board,word) || 
           f(i-1,j,ind+1,vis,board,word) || 
           f(i,j-1,ind+1,vis,board,word)) return true;
        vis[i][j]=0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size(),c=board[0].size();
        vector<vector<int>>vis(r,vector<int>(c));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(f(i,j,0,vis,board,word))
                    return true;
            }
        }
        return false;
    }
};