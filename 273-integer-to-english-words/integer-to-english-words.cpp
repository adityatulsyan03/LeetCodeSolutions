class Solution {
private:
    string helper(int num, unordered_map<int, string>& mp) {
        if (num == 0) return "";

        string ans = "";
        if (num >= 100) {
            ans += mp[num / 100] + " Hundred";
            num %= 100;
            if (num > 0) ans += " ";
        }
        if (num >= 20) {
            ans += mp[(num / 10) * 10];
            num %= 10;
            if (num > 0) ans += " ";
        }
        if (num > 0) {
            ans += mp[num];
        }
        return ans;
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        unordered_map<int, string> mp;
        mp[1] = "One";
        mp[2] = "Two";
        mp[3] = "Three";
        mp[4] = "Four";
        mp[5] = "Five";
        mp[6] = "Six";
        mp[7] = "Seven";
        mp[8] = "Eight";
        mp[9] = "Nine";
        mp[10] = "Ten";
        mp[11] = "Eleven";
        mp[12] = "Twelve";
        mp[13] = "Thirteen";
        mp[14] = "Fourteen";
        mp[15] = "Fifteen";
        mp[16] = "Sixteen";
        mp[17] = "Seventeen";
        mp[18] = "Eighteen";
        mp[19] = "Nineteen";
        mp[20] = "Twenty";
        mp[30] = "Thirty";
        mp[40] = "Forty";
        mp[50] = "Fifty";
        mp[60] = "Sixty";
        mp[70] = "Seventy";
        mp[80] = "Eighty";
        mp[90] = "Ninety";

        unordered_map<int, string> mp2;
        mp2[1000000000] = "Billion";
        mp2[1000000] = "Million";
        mp2[1000] = "Thousand";
        mp2[1] = "";

        string ans = "";

        for (const auto& i : {1000000000, 1000000, 1000, 1}) {
            int t = i;
            if (num >= t) {
                ans += helper(num / t, mp) + " " + mp2[i];
                num %= i;
                if (num > 0) ans += " ";
            }
        }

        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};