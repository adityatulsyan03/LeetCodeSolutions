class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st1,st2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st1.push(i);
            }
            
            if(s[i]=='*'){
                st2.push(i);
            }

            if(s[i]==')'){
                if(st1.size()!=0){
                    st1.pop();
                }
                else if(st2.size()!=0){
                    st2.pop();
                }
                else
                    return false;
            }
        }
        while(st1.size()!=0 && st2.size()!=0){
            if(st1.top()<st2.top()){
                st1.pop();
                st2.pop();
            }
            else{
                break;
            }
        }      
        if(st1.size()==0)
            return true;
        return false;
    }
};