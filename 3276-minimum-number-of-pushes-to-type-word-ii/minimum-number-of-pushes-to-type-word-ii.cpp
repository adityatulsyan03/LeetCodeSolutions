class Solution {
public:
    int minimumPushes(string word) {
        vector<int> a(26,0);
        for(char i:word){
            a[i-'a']++;
        }
        sort(a.rbegin(),a.rend());
        int ans=0;
        for(int i=0;i<26;i++){
            if(i<8)
                ans+= 1*a[i];
            else if(i<16)
                ans+= 2*a[i];
            else if(i<24)
                ans+= 3*a[i];
            else
                ans+= 4*a[i];
        }
        return ans;
    }
};