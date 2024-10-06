class Solution {
private:
    vector<string> splitWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> s1Words = splitWords(s1);
        vector<string> s2Words = splitWords(s2);
        if (s1Words.size() < s2Words.size()) {
            swap(s1Words, s2Words);
        }
        
        int i = 0, j = 0;
        while (i < s2Words.size() && s1Words[i] == s2Words[i]) {
            i++;
        }
        while (j < s2Words.size() && s1Words[s1Words.size() - 1 - j] == s2Words[s2Words.size() - 1 - j]) {
            j++;
        }
        return i + j >= s2Words.size();
    }
};