class Solution {
public:
    int maximum69Number (int num) {
        int i=0,a=num,j=0;
        while(a>0){
            j++;
            int t=a%10;
            if(t==6)    i=j;
            a/=10;
        }
        cout<<i<<endl;
        return num+(3*pow(10,i-1));
    }
};