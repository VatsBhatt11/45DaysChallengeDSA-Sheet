class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sg=0,sc=0;
        for(auto it:gas)
            sg+=it;
        for(auto itr:cost)
            sc+=itr;
        if(sg<sc)
            return -1;
        int total=0,ans=0;
        int n=gas.size();
        for(int i=0;i<n;i++)
        {
            total+=gas[i]-cost[i];
            if(total<0)
            {
                total=0;
                ans=i+1;
            }
        }
        return ans;
    }
};