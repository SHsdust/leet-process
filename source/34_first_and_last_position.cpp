#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int lower_bound(vector<int>& nums, int target){
        int l(0), r(nums.size()), mid;
        while(l < r){
            mid = l + (r-l)/2;
            if(nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    int upper_bound(vector<int> &nums, int target){
        int l(0), r(nums.size()), mid;
        while(l < r){
            mid = l + (r-l)/2;
            if(nums[mid] > target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n(nums.size());
        if(!n) return vector<int>({-1, -1});

        int lower(lower_bound(nums, target));
        int upper(upper_bound(nums, target) - 1);

        if(lower == n || nums[lower] != target)
            return vector<int>({-1, -1});

        return vector<int>({lower, upper});

    }
};

int main(){
    int a[10] = {2,2};
    int target(3);
    vector<int> nums(a, a+2);

    Solution s;
    vector<int> result =  s.searchRange(nums, target);
    cout << "[" << result[0] << "," << result[1] << "]" << endl;
    return 0;
}
