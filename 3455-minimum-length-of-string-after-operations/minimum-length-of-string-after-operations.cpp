class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> cnt;
        for(char i:s){
            cnt[i]++;
        }
        int ans=0;
        for(auto [i,j]:cnt){
            if(j>2){
                if(j%2==0){
                    j=2;
                }else{
                    j=1;
                }
            }
            ans+=j;
        }
        return ans;
    }
};