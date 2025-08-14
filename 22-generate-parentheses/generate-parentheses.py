class Solution:
    def helper(self, n: int, ans: set, temp: str):
        if len(temp) == n * 2:
            ans.add(temp)
        else:
            a = "()"
            for i in range(len(temp) + 1):
                t = temp[:i] + a + temp[i:]
                self.helper(n, ans, t)

    def generateParenthesis(self, n: int) -> List[str]:
        ans = set()
        self.helper(n, ans, "")
        return list(ans)