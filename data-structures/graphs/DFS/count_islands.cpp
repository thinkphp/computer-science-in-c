class Solution {
    
private:
    void dfs(int n,int m,vector<vector<char>> &grid,int r,int c)
{
    grid[r][c]='0';
    int dx[]={-1,-1,0,1,1,1,0,-1};
    int dy[]={0,-1,-1,-1,0,1,1,1};
    for(int i=0;i<8;i++)
    {
        int x=r+dx[i];
        int y=c+dy[i];
        if(x>=0&&y>=0&&x<n&&y<m&&grid[x][y]=='1')
        {
            dfs(n,m,grid,x,y);
        }
    }
}
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
    int no_of_island=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='1')
            {
                dfs(n,m,grid,i,j);
                no_of_island++;
            }
        }
    }
    return no_of_island;
    }
  
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
