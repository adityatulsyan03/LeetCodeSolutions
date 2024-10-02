class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans=0,n=arr.size();
        for(int i=0;i<n;i++){
            int temp=arr[i];
            for(int j=i+1;j<n;j++){
                temp^=arr[j];
                if(temp==0){
                    ans+=j-i;
                }
            }
        }
        return ans;
    }
};