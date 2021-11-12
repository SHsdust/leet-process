#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l(0), r(nums.size()-1), target(nums.size()-k);
        while(l < r){
            int mid(quickselect(nums, l, r));
            if(mid == target)
                return nums[mid];
            else if(mid > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return nums[l];
    }

    int quickselect(vector<int> &nums, int l, int r){
        int i(l+1), j(r);
        while(true){
            while(i<r && nums[i] <= nums[l])
                ++i;
            while(j>l && nums[j] >= nums[l])
                --j;
            if(i>=j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
    void quick_sort(vector<int> &nums, int l, int r) {
        if (l + 1 >= r) {
            return;
        }
        int first = l, last = r - 1, pivot = nums[first];
        while (first < last){
            while(first < last && nums[last] >= pivot) {
                --last;
            }
            nums[first] = nums[last];
            while (first < last && nums[first] <= pivot) {
                ++first;
            }
            nums[last] = nums[first];
        }
        nums[first] = pivot;
        quick_sort(nums, l, first);
        quick_sort(nums, first + 1, r);
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
