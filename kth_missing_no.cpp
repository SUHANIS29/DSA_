class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //arr sorted -> Binary search
        int start=0,end=arr.size()-1,ans=arr.size(),mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]-mid-1>=k){ //imp 
                ans=mid;
                end=mid-1;

            }
            else{
                start=mid+1;
            }
        }
        return ans+k;
    }
};
