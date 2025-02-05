class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size()){
            return false;
        }
        char diff='/';
        char diff2='/';
        int c=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                if(diff=='/'){
                    diff2=s1[i];
                    c++;
                    diff=s2[i];
                }else{
                    if(c>1){
                        return false;
                    }
                    if(s1[i]==diff && s2[i]==diff2){
                        c++;
                    }else{
                        return false;
                    }
                }
            }
        }
        return c==2||c==0?true:false;
    }
};