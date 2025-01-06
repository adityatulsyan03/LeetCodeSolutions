class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size(),ones=0;
        vector<int> ans(n,0);
        vector<int> prefixSum(n+1,0);
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                prefixSum[i+1]=prefixSum[i]+i;
                ones++;
            }
            else{
                prefixSum[i+1]=prefixSum[i];
            }
        }
        int r=ones,l=0;
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                l++;
                r--;
            }
            ans[i]+=(prefixSum[n]-prefixSum[i+1])-i*r;
            ans[i]+=i*l - prefixSum[i+1];
        }
        return ans;
    }
};