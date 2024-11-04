class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int curr_cnt=0;
        char curr_char=word[0];
        for(char i:word){
            if(i==curr_char){
                curr_cnt++;
                if(curr_cnt==9){
                    char temp=curr_cnt+'0';
                    ans+=temp;
                    ans+=curr_char;
                    curr_cnt=0;
                }
            }
            else{
                if(curr_cnt!=0){
                    char temp=curr_cnt+'0';
                    ans+=temp;
                    ans+=curr_char;
                }
                curr_char=i;
                curr_cnt=1;
            }
        }
        if(curr_cnt!=0){
            char temp=curr_cnt+'0';
            ans+=temp;
            ans+=curr_char;
        }
        return ans;
    }
};