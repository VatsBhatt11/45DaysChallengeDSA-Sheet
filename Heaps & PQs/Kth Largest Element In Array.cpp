class Solution {
public:
    int partition(vector<int>& arr,int l,int h)
    {
        int pivot=h;
        int i=l-1;
        for(int j=l;j<h;j++)
        {
            if(arr[j]<=arr[pivot])
            {
                i++;
                swap(arr[j],arr[i]);
            }
        }
        swap(arr[i+1],arr[h]);
        return i+1;
    }

    int helper(vector<int>& arr,int l,int h,int k)
    {
        int pivot_ind=partition(arr,l,h);
        if(pivot_ind==k-1)
            return arr[pivot_ind];
        if(pivot_ind<k-1)
            return helper(arr,pivot_ind+1,h,k);
        else
            return helper(arr,l,pivot_ind-1,k);
    }

    int findKthLargest(vector<int>& arr, int k) {
        int n=arr.size();
        return helper(arr,0,n-1,n-k+1);
    }
};