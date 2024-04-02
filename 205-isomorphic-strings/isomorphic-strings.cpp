class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return 0;
        unordered_set<char> c;
        unordered_map<char,char> check;
        for(int i=0;i<s.size();i++){
            if(check.find(s[i]) == check.end()){
                check[s[i]]=t[i];
                if(c.find(t[i])!=c.end())
                    return 0;
                c.insert(t[i]);
            }
            else{
                if(check[s[i]]!=t[i])
                    return 0;
            }
        }
        for(auto [i,j]:check)
            cout<<i<<" "<<j<<endl;
        return 1;
    }
};