#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n(isConnected.size()), count(0);
        vector<bool> visited(n, false);
        for(int i=0; i<n; ++i){
            if(!visited[i]){
                ++count;
                dfs(isConnected, visited, i);
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& isConnected,  vector<bool> &visited, int i){
        visited[i] = true;
        for(int j=0; j<isConnected.size(); ++j){
            if(isConnected[i][j]==1 && !visited[j]){
                visited[j] = true;
                dfs(isConnected, visited, j);
            }
        }
    }    
};

int main(){
    vector<vector<int>> isConnected{
        {1,1,0}, {1,1,0},{0,0,1}
    };

    Solution s;
    cout << s.findCircleNum(isConnected) << endl;
    
    return 0;
}