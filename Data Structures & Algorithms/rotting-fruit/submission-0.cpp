class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int time = 0;
        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }

        int dirs[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()) {
            int size = q.size();
            bool isRotten = false;
            for(int i = 0; i < size; i++) {
                auto top = q.front();
                q.pop();
                for(int j = 0; j < 4; j++) {
                    int row = top.first + dirs[j][0];
                    int col = top.second + dirs[j][1];
                    if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.push({row,col});
                        fresh--;
                        isRotten = true;
                    }
                }
            }
            if(isRotten) time++;
        }
        return fresh > 0 ? -1 : time;
    }
};
