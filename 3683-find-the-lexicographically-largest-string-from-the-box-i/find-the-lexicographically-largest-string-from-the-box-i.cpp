class Solution {
public:
    string answerString(string word, int numFriends) {
        if(word.size()<numFriends)  return "";
        if(numFriends==1) return word;
        int idx=0;
        char t=word[0];
        vector<int> poss;
        for(int i=0;i<word.size();i++){
            if(t<word[i]){
                idx=i;
                t=word[i];
                poss.clear();
            }
            if(t==word[i]){
                poss.push_back(i);
            }
        }
        string ans="";
        int n=word.size()-numFriends+1;
        for(int i:poss){
            string temp=word.substr(i,n);
            ans=ans>temp?ans:temp;
        }
        return ans;
    }
};