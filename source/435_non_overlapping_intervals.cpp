#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        int si(intervals.size());
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        int removed(0), tail(intervals[0][1]);
        for(int i=1; i<si; ++i)
            if(intervals[i][0] < tail)
                ++removed;
            else
                tail = intervals[i][1];
        return removed;
    }
};

int main(){
    int a[20][20] = {{1,3}, {1,2}, {2,3}};
    vector<vector<int>> intervals;
    for(int i=0; i<3; ++i){
        intervals.push_back(vector<int>(a[i], a[i]+2));
    }

    Solution s;
    cout << s.eraseOverlapIntervals(intervals) << endl;
    return 0;
}
