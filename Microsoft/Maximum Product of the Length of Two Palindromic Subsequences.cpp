// Link: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/submissions/1493800593/

class Solution {
public:
    int maxProduct(const string& s) {
        int n = s.size();
        vector<int> dp(1 << n, 0);

        for (int mask = 1; mask < (1 << n); ++mask) {
            string subsequence;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) subsequence += s[i];
            }
            dp[mask] = lps(subsequence);
        }

        int maxProduct = 0;
        for (int mask1 = 1; mask1 < (1 << n); ++mask1) {
            for (int mask2 = mask1; mask2 < (1 << n); ++mask2) {
                if ((mask1 & mask2) == 0) {
                    maxProduct = max(maxProduct, dp[mask1] * dp[mask2]);
                }
            }
        }

        return maxProduct;
    }

private:
    int solve(const string& a, const string& b, int i, int j, vector<vector<int>>& dp) {
        if (i >= a.length() || j >= b.length()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (a[i] == b[j]) return dp[i][j] = 1 + solve(a, b, i + 1, j + 1, dp);
        return dp[i][j] = max(solve(a, b, i + 1, j, dp), solve(a, b, i, j + 1, dp));
    }

    int lps(const string& s) {
        string reversedS = s;
        reverse(reversedS.begin(), reversedS.end());
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(s, reversedS, 0, 0, dp);
    }
};
