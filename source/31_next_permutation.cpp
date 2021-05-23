#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

// STL Sollution
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // nextPermutation(nums);
        next_permutation(nums.begin(), nums.end());
    }
};



int main(){
    int arr[10] = {1,1,5};
    vector<int> nums(arr, arr+3);

    Solution s;
    s.nextPermutation(nums);

    cout << "[";
    for(auto p=nums.begin(); p!=nums.end(); ){
        cout << " " << *p ;
        if(++p != nums.end())
            cout << ",";
    }
    cout << " ]" << endl;
    return 0;
}
