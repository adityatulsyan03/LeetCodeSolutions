class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> s;
        for(int i=0;i<digits.size();i++){
            if(digits[i]%2==0){
                for(int j=0;j<digits.size();j++){
                    if(j==i) continue;
                    for(int k=0;k<digits.size();k++){
                        if(k==i || k==j || digits[k]==0) continue;
                        int t=digits[k]*100;
                        t+=digits[j]*10;
                        t+=digits[i];
                        s.insert(t);
                    }
                }
            }
        }
        vector<int> ans(s.begin(),s.end());
        return ans;
    }
};