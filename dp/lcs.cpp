
int lcs(string &s, string &t, int i, int j, vector<vector<int>> &dp){//initialize dp with -1
        if(i == -1 or j == -1) return 0;
  
        int &result = dp[i][j];
        if(result != -1) return result;
        
        if(s[i] == t[j])
            result = 1 + lcs(s, t, i-1, j-1, dp);
  
        return result = max({result, lcs(s,t, i-1, j, dp), lcs(s,t,i,j-1, dp)});
 }
