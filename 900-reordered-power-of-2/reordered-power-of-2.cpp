class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        for(int i=0;i<30;i++){
            int a=1<<i;
            string s2=to_string(a);
            if(s.size()<s2.size())
                return false;
            sort(s2.begin(),s2.end());
            if(s2==s)
                return true;
        }
        return false;
    }
};