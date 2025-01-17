class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        int cnt=0;
        bool minus=false;
        bool add=false;
        const int INTMAX = 2147483647;
        const int INTMIN = -2147483648;

        for(char c:s){
            
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || 
                ((c=='-' || c==' ' || c=='+') && (ans!=0 || cnt!=0 || minus || add)) || c=='.')
            {  
                break;
            }
            if(c==' '){
                continue;
            }
            if(c=='-'){
                minus=true;
                continue;
            }
            if (c == '+') {
                add=true;
                continue;
            }
            if (ans > (INTMAX - (c - '0')) / 10) {
                return minus ? INTMIN : INTMAX;
            }

            ans = (ans * 10) + (c - '0');
            cnt++;
        }
        return minus?ans*-1:ans;
    }
};