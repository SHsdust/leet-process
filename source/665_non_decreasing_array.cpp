#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

// interesting, think about different cases in mind;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool special(false);
        int count(0), n(nums.size());
        for(int i=0; i<n-1; ++i){
            if(nums[i] > nums[i+1])
                ++count;
            if(i>=1 && i<=n-3 && nums[i]>nums[i+1] && nums[i-1]>nums[i+1] && nums[i-1]<=nums[i] && nums[i+2]>=nums[i+1] \
               && nums[i+2]<nums[i])
                special = true;
        }
        return (count<=1) && !special;
    }
};

int main(){
    int arr[10] = {2, 3, 3, 2, 2};
    vector<int> nums(arr, arr+5);

    Solution s;
    cout << s.checkPossibility(nums) << endl;
    return 0;
}
