class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int check=0;
        unordered_map<int,int> even,odd,cnt;
        for(int i=0;i<s1.size();i++){
            if(i%2==1){
                odd[s1[i]]++;
                odd[s2[i]]++;
                if(odd[s1[i]]%2==0){ 
                    odd.erase(s1[i]);
                }
                if(odd[s2[i]]%2==0){
                    odd.erase(s2[i]);
                }
            }
            else{
                even[s1[i]]++;
                even[s2[i]]++;
                if(even[s1[i]]%2==0){
                    even.erase(s1[i]);
                }
                if(even[s2[i]]%2==0){
                    even.erase(s2[i]);
                }
            }
            cnt[s1[i]]++;
            cnt[s2[i]]--;
            if(cnt[s1[i]]==0)   cnt.erase(s1[i]);
            if(cnt[s2[i]]==0)   cnt.erase(s2[i]);
        }
        return !cnt.size() && !odd.size() && !even.size();
    }
};