class Solution {
public:
    int lcs(string s, string t, int n, int m){
        vector<vector<int>> dp(n+1, vector<int> (m+1));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }
                else{
                    if(s[i-1] == t[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else{
                         dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }
        return dp[n][n];
    }
    
    int longestPalindromeSubseq(string s) {
        string t = s;
        int n = s.length();
        reverse(s.begin(), s.end());
        return lcs(s, t, n, n);
    }
};