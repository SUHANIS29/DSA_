//min kitne banana (k/hr) khayega koko to finish all in given hr.
//arr= each pile kitna banana hai...

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=0,end=0,mid,ans,n=piles.size();
        long long sum=0;
     for(int i=0;i<n;i++){
        //start+=piles[i]; //error aya..! integer overflow so ->long long sum
        sum+=piles[i];
        end=max(end,piles[i]); //worst case= eat all bananas in 1hr :(
     }
     start=sum/h;
     if(!start){
        start=1; //to avoid mid=0
     }
     while(start<=end){
        mid=start+(end-start)/2;
        //mid- no of b consume /hr
int total_time=0;
for(int i=0;i<n;i++){
    total_time+=piles[i]/mid; //1hr + baki remaining hr //error as mid=0 so startt!=0
if(piles[i]%mid) 
total_time++;
}
if(total_time>h)
{
    start=mid+1;

}
else{
    ans=mid;
    end=mid-1;
}
     }
     return ans;
    }
};
