class TrieNode {
public:
    char node;
    unordered_map<char, TrieNode*> child;
    bool isEnd;
    TrieNode(char node) {
        this->node = node;
        isEnd = false;
    }
};

class Solution {
private:
    TrieNode* root;
    
    void buildTrie(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->child.find(c) == cur->child.end())
                cur->child[c] = new TrieNode(c);
            cur = cur->child[c];
        }
        cur->isEnd = true;
    }

    vector<string> splitString(string& s, char delimiter) {
        vector<string> ans;
        int start = 0;
        int end = s.find(delimiter, start);
        while (end != string::npos) {
            string sub = s.substr(start, end - start);
            ans.push_back(sub);
            start = end + 1;
            end = s.find(delimiter, start);
        }
        string sub = s.substr(start);
        ans.push_back(sub);
        return ans;
    }

    string queryTrie(string word) {
        TrieNode* cur = root;
        string s = "";
        for (auto c : word) {
            if (cur->child.find(c) == cur->child.end()) return word;
            cur = cur->child[c];
            s += c;
            if (cur->isEnd) return s;
        }
        return word;
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode('/');
        for (auto word : dictionary) buildTrie(word);

        vector<string> splitSentences = splitString(sentence, ' ');
        string ans = "";
        for (int i = 0; i < splitSentences.size(); i++) {
            ans += queryTrie(splitSentences[i]) + ((i != splitSentences.size() - 1) ? " " : "");
        }
        return ans;
    }
};