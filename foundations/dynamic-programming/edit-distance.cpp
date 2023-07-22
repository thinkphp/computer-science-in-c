int minDistance(string word1, string word2) {
    auto min3=[](int a,int b,int c)
    {
        return min(a,min(b,c));
    };
    int m=word1.size();
    int n=word2.size();
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;++i)
    {
        dp[i][0]=i;
    }
    for(int i=1;i<=n;++i)
    {
        dp[0][i]=i;
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(word1[i-1]==word2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min3(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
