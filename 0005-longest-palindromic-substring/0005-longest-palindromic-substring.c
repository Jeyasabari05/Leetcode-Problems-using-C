char * longestPalindrome(char * s){
    int n = strlen(s);
    int begin = 0;
    int longest = 1;
    bool dp[n][n];
    memset( dp, false, n*n*sizeof(bool) );
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }
    for (int length = 2; length <= n; length++)
    {
        for (int start = 0; start < n; start++)
        {
            int end = start + length - 1;
            if (end >= n)
            {
                break;
            }
            if (s[start] != s[end])
            {
                dp[start][end] = false;
            }
            else
            {
                if (length <= 2)
                {
                    dp[start][end] = true;
                }
                else
                {
                    dp[start][end] = dp[start+1][end-1];
                }
            }
            if (dp[start][end])
            {
                if (length > longest)
                {
                    longest = length;
                    begin = start;
                }
            }
        }
    }
    char *result = malloc(n+1);
    strncpy(result, s+begin, longest);
    result[longest] = 0;
    return result;
}