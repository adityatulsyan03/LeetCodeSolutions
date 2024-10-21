class Solution {
private:
    int helper(int start,string& s,unordered_set<string> subs){
        if(start==s.size()) return 0;
        int mx=0;
        for(int end=start+1;end<=s.size();end++){
            string substring=s.substr(start,end-start);
            if(subs.find(substring)==subs.end()){
                subs.insert(substring);
                mx=max(mx,1+helper(end,s,subs));
                subs.erase(substring);
            }
        }
        return mx;
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> subs;
        return helper(0,s,subs);
    }
};