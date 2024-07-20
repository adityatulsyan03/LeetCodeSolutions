class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int num = 0;
        char op = '+';
        
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1) {
                if (op == '+') {
                    nums.push(num);
                } else if (op == '-') {
                    nums.push(-num);
                } else if (op == '*') {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top * num);
                } else if (op == '/') {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top / num);
                }
                op = s[i];
                num = 0;
            }
        }
        
        int result = 0;
        while (!nums.empty()) {
            result += nums.top();
            nums.pop();
        }
        
        return result;
    }
};