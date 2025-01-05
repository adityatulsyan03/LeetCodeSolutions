class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> shiftArray(n,0);
        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            shiftArray[start] += (direction == 1) ? 1 : -1;
            if(end+1<n)
                shiftArray[end + 1] += (direction == 1) ? -1 : 1;
        }
        for (int i = 1; i < n; i++)
            shiftArray[i] += shiftArray[i-1];
        string ans;
        for(int i=0;i<n;i++)
            ans += ((s[i] - 'a' + shiftArray[i]) % 26 + 26) % 26 + 'a';
        return ans;
    }
};