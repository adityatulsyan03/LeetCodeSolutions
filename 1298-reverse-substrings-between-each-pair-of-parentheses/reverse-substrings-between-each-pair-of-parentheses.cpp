class Solution {
public:
    string reverseParentheses(string s) {
        string a="";
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!='(' && s[i]!=')')
                a+=s[i];
            else if(s[i]=='('){
                st.push(a);
                st.push("(");
                a="";
            }
            else{
                cout<<i<<endl;
                st.push(a);
                a="";
                string temp="";
                while (!st.empty() && st.top() != "(") {
                    temp = st.top() + temp;
                    st.pop();
                }
                if (!st.empty() && st.top() == "(") {
                    st.pop();
                }
                reverse(temp.begin(),temp.end());
                st.push(temp);
            }
        }
        string ans=a;
        while(!st.empty()){
            cout<<st.top()<<endl;
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};