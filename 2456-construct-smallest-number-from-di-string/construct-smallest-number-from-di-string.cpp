class Solution {
public:
    string smallestNumber(string pattern) {
        string res, stack;
        for (int i = 0; i <= pattern.length(); i++) {
            stack.push_back('1' + i);
            if (i == pattern.length() || pattern[i] == 'I') {
                while (!stack.empty()) {
                    res.push_back(stack.back());
                    stack.pop_back();
                }
            }
        }
        return res;
    }
};