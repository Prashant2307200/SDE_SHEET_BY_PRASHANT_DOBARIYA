#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            int minCut = i; // max cuts
            for (int j = 0; j <= i; ++j) {
                if (s[j] == s[i] && (i - j <= 1 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;
                    minCut = (j == 0) ? 0 : min(minCut, dp[j - 1] + 1);
                }
            }
            dp[i] = minCut;
        }
        return dp[n - 1];
    }
};
