class Solution {
private:
    bool equal(vector<int> arr,vector<int> pern){
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=pern[i])
                return 0;
        }
        return 1;
    }
public:
    int reinitializePermutation(int n) {
        vector<int> pern;
        for(int i=0;i<n;i++)    pern.push_back(i);
        vector<int> prev=pern;
        for(int t=0;t<1000;t++){
            vector<int> arr;
            for(int i=0;i<n;i++){
                if(i%2==0){
                    arr.push_back(prev[i/2]);
                }
                else{
                    arr.push_back(prev[n/2 + (i-1)/2]);
                }
            }
            prev=arr;
            if(equal(prev,pern)){
                return t+1;
            }
        }
        return -1;
    }
};