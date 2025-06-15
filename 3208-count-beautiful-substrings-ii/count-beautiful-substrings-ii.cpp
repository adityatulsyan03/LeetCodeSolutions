class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        int n = s.size(), v = 0, l;
        for(l=1;l*l %(k*4);l++);
        set<char> vo = {'a','e','i','o','u'};

        vector<unordered_map<int,int>> seen(l);

        seen[l-1][0]=1;
        long long ans=0;

        for(int i=0;i<n;i++){
            v += vo.find(s[i]) != vo.end() ? 1:-1;
            ans += seen[i%l][v]++;
        }

        return ans;
    }
};