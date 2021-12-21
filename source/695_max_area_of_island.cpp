#include "iostream"
#include "vector"
#include "algorithm"
#include "stack"
using namespace std;

vector<int> directions{
    -1, 0, 1, 0, -1
};

// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int n(grid.size());
//         int m(n ? grid[0].size() : 0);
//         int local_area, area(0), x, y;
//         for(int i=0; i<n; ++i)
//             for(int j=0; j<m; ++j){
//                 if(grid[i][j]){
//                     grid[i][j] = 0;
//                     local_area = 1;
//                     stack<pair<int, int>> island;
//                     island.push({i, j});

//                     while(!island.empty()){
//                         auto [p ,q] = island.top();
//                         island.pop();
//                         for(int k=0; k<4; ++k){
//                             x = p + directions[k], y = q + directions[k+1];
//                             if(x>=0 && x<n && y>=0 && y<m && grid[x][y]){
//                                 ++local_area;
//                                 grid[x][y] = 0;
//                                 island.push({x, y});
//                             }
//                         }
//                     }
//                     area = max(area, local_area);
//                 }
//             }
//         return area;
//     }
// };

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size()==0) return 0;
        int max_area(0);
        for(int i=0; i<grid[0].size(); ++i){
            for(int j=0; j<grid.size(); ++j){
                if(grid[j][i]==1){
                    max_area  = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }


    int dfs(vector<vector<int>> &grid, int i, int j){
        if(grid[j][i]==0) return 0;
        grid[j][i] = 0;
        int area = 1;
        int x, y;
        for(int k=0; k<4; ++k){
            x = i + directions[k];
            y = j + directions[k+1];
            if(x>=0 && x<grid[0].size() && y>=0 && y<grid.size()){
                area += dfs(grid, x, y);
            }
        }
        return area;
    }
};

int main(){
    vector<vector<int>> grid{
        {0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0}, \
        {0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0}, \
        {0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}
    };


    Solution s ;
    cout << s.maxAreaOfIsland(grid) << endl;
    return 0;
}
