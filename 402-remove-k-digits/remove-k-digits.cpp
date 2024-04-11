class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> ans;
        int i=0;
        while(k!=0 && i<num.size()){
            while (!ans.empty() && k > 0 && ans.top() > num[i]) {
                ans.pop();
                k--;
            }
            ans.push(num[i]);
            i++;
        }

        while(i<num.size())
            ans.push(num[i++]);

        while (k > 0 && !ans.empty()) {
            ans.pop();
            k--;
        }

        string a;
        while(!ans.empty()){
            a+=ans.top();
            ans.pop();
        }

        reverse(a.begin(),a.end());
        
        int pos = 0;
        while (pos < a.size() && a[pos] == '0') {
            pos++;
        }
        
        return (pos == a.size()) ? "0" : a.substr(pos);
    }
};