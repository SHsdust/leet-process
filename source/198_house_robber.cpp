#include "iostream"
#include "vector"
using namespace std;
// DP

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size()+1, 0);
        dp[1] = nums[0];
        for(unsigned i=2; i<=nums.size(); ++i)
            dp[i] = max(dp[i-1], nums[i-1]+dp[i-2]);
        return dp[nums.size()];
    }

    int rob2(vector<int>& nums){
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[1], nums[0]);
        int pre2{nums[0]}, pre1(max(pre2, nums[1])), cur;
        for(unsigned i=2; i<nums.size(); ++i){
            cur = max(pre1, pre2+nums[i]);
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};

int main(){
    auto nums = vector<int>{
        2,7,9,3,1
    };
    Solution s;
    cout << s.rob(nums) << endl;
    cout << s.rob2(nums) << endl;
    return 0;
}
