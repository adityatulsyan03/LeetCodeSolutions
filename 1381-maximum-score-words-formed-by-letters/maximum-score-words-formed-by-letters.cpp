class Solution {
private:
    int backtrack(vector<string>& words, vector<int>& lettersFreq, vector<int>& score, int idx) {
        if (idx == words.size()) {
            return 0;
        }

        // Option 1: Skip the current word
        int skip = backtrack(words, lettersFreq, score, idx + 1);

        // Option 2: Include the current word (if possible)
        vector<int> wordFreq(26, 0);
        int wordScore = 0;
        bool canForm = true;

        for (char c : words[idx]) {
            int code = c - 'a';
            wordFreq[code]++;
            if (wordFreq[code] > lettersFreq[code]) {
                canForm = false;
            }
            wordScore += score[code];
        }

        int use = 0;
        if (canForm) {
            for (char c : words[idx]) {
                lettersFreq[c - 'a']--;
            }
            use = wordScore + backtrack(words, lettersFreq, score, idx + 1);
            for (char c : words[idx]) {
                lettersFreq[c - 'a']++;
            }
        }

        return max(skip, use);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> lettersFreq(26, 0);
        for (char letter : letters) {
            lettersFreq[letter - 'a']++;
        }
        
        return backtrack(words, lettersFreq, score, 0);
    }
};