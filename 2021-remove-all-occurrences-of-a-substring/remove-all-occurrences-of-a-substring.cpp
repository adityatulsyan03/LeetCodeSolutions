class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)!=string::npos){
            int index=s.find(part);
            s.erase(s.begin()+index,s.begin()+index+part.size());
        }
        return s;
    }
};