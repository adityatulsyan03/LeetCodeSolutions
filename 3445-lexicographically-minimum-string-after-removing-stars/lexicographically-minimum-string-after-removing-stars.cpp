class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        vector<bool> vis(n,true);
        unordered_map<char,set<int>> idx;
        set<char> ch;

        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                idx[s[i]].insert(i);
                ch.insert(s[i]);
                continue;
            }
            vis[i]=false;
            char smallest = *ch.begin();
            cout<<smallest<<endl;
            int lastIdx = *idx[smallest].rbegin();
            vis[lastIdx]=false;
            idx[smallest].erase(lastIdx);
            if(idx[smallest].size()==0){
                ch.erase(smallest);
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(vis[i])
                ans+=s[i];
        }
        return ans;
    }
};