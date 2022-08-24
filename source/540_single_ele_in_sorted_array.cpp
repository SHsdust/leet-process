#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    bool Twice(vector<int> &nums, int i){
        int count(0), size(nums.size()-1);
        if(i==0){
            if(nums[0]==nums[1])
                ++count;
        }
        else if(i==size){
            if(nums[size]==nums[size-1])
                ++count;
        }
        else if(nums[i-1]==nums[i] || nums[i+1]==nums[i])
                ++count;
        return count;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int l(0), r(nums.size()-1);
        while(l<r){
            int mid = l + (r-l) / 2;
            if(Twice(nums, mid)){
                if(nums[mid-1]==nums[mid]){
                    int index(mid-1);
                    if(index%2==0)
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
                else{
                    if(mid%2==0)
                        l = mid + 2;
                    else
                        r = mid;
                }
            }
            else
                return nums[mid];
        }
        return nums[l];
    }
};

int main(){
    int arr[105] = {1,2,2,3,3};
    vector<int> nums(arr, arr+5);

    Solution s;
    cout << s.singleNonDuplicate(nums) << endl;
    return 0;
}
