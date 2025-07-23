class Solution {
private:
    void swapChars(string &s, char a, char b) {
        for (char &c : s) {
            if (c == a) c = b;
            else if (c == b) c = a;
        }
    }
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            swapChars(s, 'a', 'b');
        }

        int ans = 0;
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && st.top() == 'a' && c == 'b') {
                st.pop();
                ans += x;
            } else {
                st.push(c);
            }
        }

        stack<char> st2;
        while (!st.empty()) {
            char c = st.top(); st.pop();
            if (!st2.empty() && st2.top() == 'a' && c == 'b') {
                st2.pop();
                ans += y;
            } else {
                st2.push(c);
            }
        }

        return ans;
    }
};