class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> cnt;
        cnt[5]=0;
        cnt[10]=0;
        for(int i:bills){
            if(i==5){
                cnt[5]++;
            }
            else if(i==10){
                if(cnt[5]==0)   return false;
                cnt[5]--;
                cnt[10]++;
            }
            else{
                if(cnt[5]==0) return false;
                if(cnt[10]==0){
                    if(cnt[5]<3)    return false;
                    cnt[5]-=3;
                }
                else{
                    cnt[5]--;
                    cnt[10]--;
                }
            }
        }
        return true;
    }
};