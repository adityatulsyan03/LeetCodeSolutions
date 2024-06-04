class Solution {
public:
    int longestPalindrome(string s) {
        int arr[52]={0};
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z')
                arr[s[i]-'a']++;
            else
                arr[s[i]-'A'+26]++;
        }
        int oddcount=0;
        for(int i=0;i<52;i++){
            if(arr[i]%2==1)
                oddcount++;
        }
        if(oddcount>1)
            return s.size()-oddcount+1;
        return s.size();
    }
};