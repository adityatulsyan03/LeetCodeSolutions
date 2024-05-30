class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans=0,n=arr.size(),xora;
        vector<int> prefix=arr;
        for(int i=1;i<prefix.size();i++)
            prefix[i]^=prefix[i-1];
        for(int i=0;i<n;i++){
            xora=arr[i];
            for(int k=i+1;k<n;k++){
                xora^=arr[k];
                if(xora==0)
                    ans+=(k-i);
            }
        }
        return ans;
    }
};