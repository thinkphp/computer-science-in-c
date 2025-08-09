class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    ans++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto curr = q.front();
                        q.pop();
                        int x = curr.first;
                        int y = curr.second;
                        vis[x][y] = 1;
                        for(int l=0;l<4;l++){
                            int r =x+drow[l];
                            int c =y+dcol[l];
                            if(r>=0 && r<n && c>=0 && c<m && vis[r][c]==0 && grid[r][c]=='1'){
                                q.push({r,c});
                                vis[r][c]=1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
