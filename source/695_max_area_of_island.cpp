#include "iostream"
#include "vector"
#include "algorithm"
#include "stack"
using namespace std;

vector<int> directions{
    -1, 0, 1, 0, -1
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n(grid.size());
        int m(n ? grid[0].size() : 0);
        int local_area, area(0), x, y;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    local_area = 1;
                    stack<pair<int, int>> island;
                    island.push({i, j});

                    while(!island.empty()){
                        auto [p ,q] = island.top();
                        island.pop();
                        for(int k=0; k<4; ++k){
                            x = p + directions[k], y = q + directions[k+1];
                            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]){
                                ++local_area;
                                grid[x][y] = 0;
                                island.push({x, y});
                            }
                        }
                    }
                    area = max(area, local_area);
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
