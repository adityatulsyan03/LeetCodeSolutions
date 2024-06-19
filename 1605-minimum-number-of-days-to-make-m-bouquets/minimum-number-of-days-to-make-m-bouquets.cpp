class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=-1,s=1,e= *max_element(bloomDay.begin(),bloomDay.end());
        if(bloomDay.size()<((long)m*k))
            return -1;
        while(s<=e){ 
            int mid = (s+e)/2;
            int cnt=0,temp=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid)
                    cnt++;
                else
                    cnt=0;
                if(cnt==k){
                    temp++;
                    cnt=0;
                }
            }
            if(temp>=m){
                ans=mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};