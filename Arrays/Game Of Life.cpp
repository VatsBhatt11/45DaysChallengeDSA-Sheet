class Solution {
public:
    int count(vector<vector<int>>& board,int r,int c)
    {
        int cnt=0;
        for(int i=r-1;i<=r+1;i++)
        {
            for(int j=c-1;j<=c+1;j++)
            {
                if(i<0 || j<0 || i==board.size() || j==board[0].size()
                || (i==r && j==c))
                    continue;
                if(board[i][j]==1 || board[i][j]==3)
                    cnt++;
            }
        }
        return cnt;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int r=board.size(),c=board[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int ng=count(board,i,j);
                if(board[i][j])
                {
                    if(ng==2 || ng==3)
                        board[i][j]=3;
                }
                else if(ng==3)
                    board[i][j]=2;
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==1)
                    board[i][j]=0;
                else if(board[i][j]==2 || board[i][j]==3)
                    board[i][j]=1;
            }
        }
    }
};