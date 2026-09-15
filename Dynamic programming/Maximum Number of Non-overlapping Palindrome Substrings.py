class Solution:
    def maxPalindromes(self, s, k):
        n = len(s)
        dp = [0] * (n + 1)

        def is_palindrome(l, r):
            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            return True

        for i in range(n):
            dp[i + 1] = max(dp[i + 1], dp[i])

            if i + k <= n and is_palindrome(i, i + k - 1):
                dp[i + k] = max(dp[i + k], dp[i] + 1)

            if i + k + 1 <= n and is_palindrome(i, i + k):
                dp[i + k + 1] = max(dp[i + k + 1], dp[i] + 1)

        return dp[n]
