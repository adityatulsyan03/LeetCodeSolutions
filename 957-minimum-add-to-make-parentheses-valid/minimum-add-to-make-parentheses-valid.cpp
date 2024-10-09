class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> p;
        for(char i:s){
            if(p.empty() || i=='(')
                p.push(i);
            else{
                if(p.top() == '(')
                    p.pop();
                else
                    p.push(i);
            }
        }
        return p.size();
    }
};