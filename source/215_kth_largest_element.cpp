#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](int &a, int &b){
            return a>=b;
        });
        return nums[k-1];
    }
};

int main(){
    int arr[10] = {2,3,5,1,54,4};
    vector<int> nums(arr, arr+6);
    int k(3);

    Solution s;
    cout << s.findKthLargest(nums, k) << endl;
    return 0;
}
