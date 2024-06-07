class Solution {
private:
    vector<string> splitSentence(const string& sentence) {
        vector<string> result;
        istringstream iss(sentence);
        string word;
        while (iss >> word) {
            result.push_back(word);
        }
        return result;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string,int> cnt;
        for(string i:dictionary)
            cnt[i]=1;
        string ans="";
        dictionary = splitSentence(sentence);
        for(string i:dictionary){
            string temp="";
            for(char j:i){
                temp+=j;
                if(cnt[temp]>0 || temp==i){
                    ans+= temp;
                    break;
                }
            }
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};