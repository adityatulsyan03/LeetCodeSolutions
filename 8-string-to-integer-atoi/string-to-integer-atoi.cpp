class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        int n=0;
        bool f=false;
        bool a=false;
        const int INTMAX = 2147483647;
        const int INTMIN = -2147483648;
        for(char c:s){
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || 
                (c==' ' && ans!=0) || c=='.')
            {  
                break;
            }
            if(c==' '){
                if(n!=0 || f || a){
                    break;
                }else{
                    continue;
                }
            }
            if(c=='-'){
                if(a || f){
                    break;
                }
                if(n==0){
                    f=true;
                    continue;
                }else{
                    break;
                }
            }
            if (c == '+') {
                if(n!=0 || f || a){
                    break;
                }
                a=true;
                continue;
            }
            if (c >= '0' && c <= '9') {
                if (ans > (INTMAX - (c - '0')) / 10) {
                    return f ? INTMIN : INTMAX;
                }

                ans = (ans * 10) + (c - '0');
                n++;
            } else {
                break;
            }
        }
        return f?ans*-1:ans;
    }
};