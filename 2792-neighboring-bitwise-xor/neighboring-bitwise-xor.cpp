class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int> temp1(n,0),temp2(n,1);
        for(int i=0;i<n-1;i++){
            temp1[i+1]=temp1[i]^derived[i];
            temp2[i+1]=temp2[i]^derived[i];
        }
        return (derived[n-1]==temp2[n-1]^temp2[0]) || (derived[n-1]==temp1[n-1]^temp1[0]);
    }
};