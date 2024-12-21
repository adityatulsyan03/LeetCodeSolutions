class Solution {
public:
    static string repeatLimitedString(string& s, int k) {
        vector<int> freq(26,0);
        priority_queue<pair<char,int>> pq;
        for(char i:s)
            freq[i-'a']++;
        
        for(int i=0;i<26;i++){
            if(freq[i]!=0)
                pq.push({i+'a',freq[i]});
        }
        string ans;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            char ch = top.first;
            int f=top.second;
            if(f<=k){
                for(int i=0;i<f;i++){
                    ans+=ch;
                }
            }
            else{
                for(int i=0;i<k;i++){
                    ans+=ch;
                }
                if (!pq.empty()) {
                    auto t = pq.top(); 
                    pq.pop();
                    ans += t.first;
                    if (t.second > 1) {
                        pq.push({t.first, t.second - 1});
                    }
                    if (f - k > 0) {
                        pq.push({ch, f - k});
                    }
                }
            }
        }
        return ans;
    }
};