class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> mp;
        mp[1]="I";
        mp[5]="V";
        mp[10]="X";
        mp[50]="L";
        mp[100]="C";
        mp[500]="D";
        mp[1000]="M";
        mp[4]="IV";
        mp[9]="IX";
        mp[40]="XL";
        mp[90]="XC";
        mp[400]="CD";
        mp[900]="CM";
        int n=1;
        string ans="";
        while(num>0){
            int c=num%10;
            num=num/10;
            string temp="";
            while(c>0){
                int t=c*n;
                if(c==9 || c==4){
                    temp+=mp[t];
                    if(c==9)    c-=9;
                    else    c-=4;
                }
                else if(c>=5){
                    temp+=mp[5*n];
                    c-=5;
                }
                else{
                    temp+=mp[n];
                    c--;
                }
            }
            ans=temp+ans;
            n*=10;
        }
        return ans;
    }
};