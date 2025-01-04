class Solution {
private:
    void backtrack(vector<string>& arr, string current, int index, int& maxLength) {
        if (hasUniqueChars(current)) {
            maxLength = max(maxLength, (int)current.length());
        }
        for (int i = index; i < arr.size(); i++) {
            backtrack(arr, current + arr[i], i + 1, maxLength);
        }
    }
    bool hasUniqueChars(const string& str) {
        unordered_set<char> charSet;
        for (char c : str) {
            if (charSet.find(c) != charSet.end()) {
                return false;
            }
            charSet.insert(c);
        }
        return true;
    }
public:
    int maxLength(vector<string>& arr) {
        int maxLength = 0;
        backtrack(arr, "", 0, maxLength);
        return maxLength;
    }
};