class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks,int ladders) {
        int i;
        priority_queue<int>q;
        for(i=0;i<heights.size()-1;i++)
        {
            if(heights[i]>=heights[i+1])
                continue;
            int dif=heights[i+1]-heights[i];
            if(bricks>=dif)
            {
                q.push(dif);
                bricks-=dif;
            }
            else if(ladders>0)
            {
                if(!q.empty() && q.top()>dif)
                {
                    bricks+=q.top();
                    q.pop();
                    q.push(dif);
                    bricks-=dif;
                }
                ladders--;
            }
            else
                break;
        }
        return i;
    }
};