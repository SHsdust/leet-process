#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

// binary search
class Solution {
public:
    bool search(vector<int>& nums, int target){
        int l(0), r(nums.size()-1), mid;
        while(l <= r){
            mid = l + (r - l)/2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] == nums[l])
                ++l;
            else if(nums[mid] <= nums[r]){
                if(target > nums[mid] && target <= nums[r])
                    l = mid +1;
                else
                    r = mid - 1;
            }
            else{
                if(target >= nums[l] && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return false;
    }
};

int main(){
    int arr[25] = {3,5,1};
    int target(5);
    vector<int> nums(arr, arr+3);

    Solution s;
    cout << s.search(nums, target) << endl;
    return 0;
}
