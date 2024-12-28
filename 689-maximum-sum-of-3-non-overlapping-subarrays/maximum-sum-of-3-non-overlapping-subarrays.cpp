class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefSum(n+1,0);
        for(int i=1;i<=n;i++){
            prefSum[i]=prefSum[i-1]+nums[i-1];
        }
        vector<int> leftMaxIdx(n,0);
        int maxSum=prefSum[k]-prefSum[0];
        for(int i=k;i<n;i++){
            int currSum=prefSum[i+1]-prefSum[i+1-k];
            if(currSum>maxSum){
                maxSum=currSum;
                leftMaxIdx[i]=i+1-k;
            }else{
                leftMaxIdx[i]=leftMaxIdx[i-1];
            }
        }
        vector<int> rightMaxIdx(n,0);
        maxSum=prefSum[n]-prefSum[n-k];
        rightMaxIdx[n-k]=n-k;
        for(int i=n-k-1;i>=0;i--){
            int currSum=prefSum[i+k]-prefSum[i];
            if(currSum>=maxSum){
                maxSum=currSum;
                rightMaxIdx[i]=i;
            }else{
                rightMaxIdx[i]=rightMaxIdx[i+1];
            }
        }
        vector<int> ans(3,0);
        maxSum=0;
        for(int i=k;i<=n-2*k;i++){
            int left=leftMaxIdx[i-1];
            int right=rightMaxIdx[i+k];
            int currSum= (prefSum[left+k]-prefSum[left])+
                        (prefSum[i+k]-prefSum[i])+
                        (prefSum[right+k]-prefSum[right]);
            if(currSum>maxSum){
                maxSum=currSum;
                ans={left,i,right};
            }
        }
        return ans;
    }
};