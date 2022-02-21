#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

vector<int> directions = {-1, 0, 1, 0, -1};

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m(grid.size()), n(grid[0].size());
        queue< pair<int ,int> > points;
        bool flipped(false);
        for(int i=0; i<m; ++i){
            if(flipped) break;
            for(int j=0; j<m; ++j)
                if(grid[i][j] == 1){
                    dfs(points, grid, m, n, i, j);
                    flipped = true;
                    break;
                }
        }
        int x, y;
        int level(0);
        while(!points.empty()){
            ++level;
            int n_points = points.size();
            while(n_points--){
                auto [r, c] = points.front();
                points.pop();
                for(int k=0; k<4; ++k){
                    x = r + directions[k], y = c + directions[k+1];
                    if(x>=0 && x<m && y>=0 && y<m){
                        if(grid[x][y] == 2) continue;
                        if(grid[x][y] == 1) return level;
                        points.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }

    void dfs(queue<pair<int, int>> &points, vector<vector<int>> &grid, \
             int m, int n, int i, int j){
        if(i<0 || j<0 || i==m || j==n || grid[i][j]==2)
            return ;
        if(grid[i][j] == 0){
            points.push({i, j});
            return ;
        }
        grid[i][j] = 2;
        dfs(points, grid, m, n, i-1, j);
        dfs(points, grid, m, n, i+1, j);
        dfs(points, grid, m, n, i, j-1);
        dfs(points, grid, m, n, i, j+1);
    }
};

int main(){
    vector<vector<int>> grid = {
        {0, 1}, {1, 0}
    };
    Solution s;
    cout << s.shortestBridge(grid) << endl;
    return 0;
}
