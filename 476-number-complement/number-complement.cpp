class Solution {
public:
    int findComplement(int num) {
        int ans=0,i=0;
        while(num>0){
            if(num%2==0)
                ans+= pow(2,i);
            i++;
            num/=2;
        }
        return ans;
    }
};