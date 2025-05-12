class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> cnt;
        for(int i:digits){
            if(cnt[i]==3){
                continue;
            }else{
                cnt[i]++;
            }
        }
        vector<int> digit;
        for(auto [i,j]:cnt){
            for(int k=0;k<j;k++){
                digit.push_back(i);
            }
        }
        set<int> s;
        for(int i=0;i<digit.size();i++){
            if(digit[i]%2==0){
                for(int j=0;j<digit.size();j++){
                    if(j==i) continue;
                    for(int k=0;k<digit.size();k++){
                        if(k==i || k==j || digit[k]==0) continue;
                        int t=digit[k]*100;
                        t+=digit[j]*10;
                        t+=digit[i];
                        s.insert(t);
                    }
                }
            }
        }
        vector<int> ans(s.begin(),s.end());
        return ans;
    }
};