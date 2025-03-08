class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        if(blocks.size()<k){
            return -1;
        }
        int ans=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W'){
                ans++;
            }
        }
        int t=ans;
        for(int i=k;i<blocks.size();i++){
            if(blocks[i-k]=='W'){
                t--;
            }
            if(blocks[i]=='W'){
                t++;
            }
            ans=min(ans,t);
        }
        return ans;
    }
};