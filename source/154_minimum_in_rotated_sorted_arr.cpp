#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

// built-in fun solution
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         auto it = min_element(nums.begin(), nums.end());
//         return *it;
//     }
// };

class Solution{
public:
    int findMin(vector<int>& nums){
        int l(0), r(nums.size()-1), mid;
        while(l<=r){
            int l(0), r(nums.size()-1), mid;
            while(l < r){
                mid = l + (r - l) / 2;
                if(nums[mid] < nums[r])
                    r = mid-1;
                else if(nums[mid] > nums[r])
                    l = mid;
                else
                    --r;
            }
            return nums[l];
        }
        return l;
    }
};

int main(){
    int arr[20] = {1};
    vector<int> nums(arr, arr+1);

    Solution s;
    cout << s.findMin(nums) << endl;
    return 0;
}
