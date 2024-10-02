class Solution {
public:
    int reinitializePermutation(int n) {
        int i=1,j=1,k=1;
        for(int t=0;t<1000;t++){
            if(k%2==0)  k=k/2;
            else    k=(n/2)+(k-1)/2;
            if(k==i)    return t+1;
        }
        return -1;
    }
};