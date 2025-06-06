class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        string ans="";

        unordered_map<char,int> cnt;
        set<char> ch;
        for(char c:s){
            cnt[c]++;
            ch.insert(c);
        }

        stack<char> st;
        for(int i=0;i<n;i++){
            char smallest = *ch.begin();
            st.push(s[i]);
            cnt[s[i]]--;
            if(cnt[s[i]]==0)    ch.erase(s[i]);
            while(!st.empty() && st.top()<=smallest){
                char topC = st.top();
                ans+=topC;
                st.pop();
                if(cnt[topC]==0){
                    ch.erase(topC);
                    if(!ch.empty())
                        smallest=*ch.begin();
                }
            }

        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};