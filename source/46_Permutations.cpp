#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtracking(nums, 0, result);
        return result;
    }

    void backtracking(vector<int> &nums, int level, vector<vector<int>> &result){
        if(level == nums.size()-1){
            result.push_back(nums);
            return ;
        }
        for(int i=level; i<nums.size(); ++i){
            swap(nums[i], nums[level]);
            backtracking(nums, level+1, result);
            swap(nums[i], nums[level]);
        }
    }
};

int main(){
    int arr[] = {1,2,3};
    vector<int> nums(arr, arr+3);

    Solution s;
    vector<vector<int>> result = s.permute(nums);
    cout << "[";
    for(auto i : result){
        cout << "[";
        for(auto j : i)
            cout << j << ',';
        cout << "], ";
    }
    cout  << endl;
    return 0;
}
