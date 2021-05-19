#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

// similar with prob.435
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n(points.size()), min(n);
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        int prev(points[0][1]);
        for(int i=1; i<n; ++i){
            if(points[i][0] <= prev)
                min--;
            else
                prev = points[i][1];
        }
        return min;

    }
};

int main(){
    int arr[10][2] = { {1,2}, {2,3}, {3,4}, {4,5} };
    vector<vector<int>> points;

    for(int i=0; i<4; ++i)
        points.push_back(vector<int>(arr[i], arr[i]+2));

    Solution s;
    cout << s.findMinArrowShots(points) << endl;
    return 0;
}
