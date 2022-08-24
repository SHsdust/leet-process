#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low(0), high(nums.size()-1), cur(0);
        while(cur <= high){
            if(nums[cur]==0){
                swap(nums[cur], nums[low]);
                ++low;
                ++cur;
            }
            else if(nums[cur]==2){
                swap(nums[cur], nums[high]);
                --high;
            }
            else
                ++cur;
        }
    }
};

int main(){
    int arr[] = {2, 0, 1};
    vector<int> nums(arr, arr+3);

    Solution s;
    s.sortColors(nums);
    for(const int p : nums)
        cout << p << ", ";
    cout << endl;
    return 0;
}
