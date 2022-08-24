#include "iostream"
#include "cstdio"
#include "vector"
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m(nums1.size()), n(nums2.size()), sum(m+n);
    }
};

int main(){
    int a[] = {1,3}, b[] = {2};
    vector<int> nums1(a, a+2), nums2(b, b+1);

    Solution s;
    printf("%.5f\n", s.findMedianSortedArrays(nums1, nums2));
    return 0;
}
