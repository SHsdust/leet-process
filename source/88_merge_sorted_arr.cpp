#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        cout << nums1.size()-m << ", " << nums2.size()-n << endl;
        int size1(nums1.size()-m), size2(nums2.size()-n);
        for(int i=0; i<size1; ++i)
            nums1.pop_back();
        for(int i=0; i<size2; ++i)
            nums2.pop_back();

        vector<int> :: iterator it1 = nums1.begin(), it2 = nums2.begin();

        while(it1!=nums1.end() && it2!=nums2.end()){
            if(*it1 >= *it2){
                nums1.insert(it1, *it2);
                ++it2;
                ++it1;
            }
            else
                ++it1;
        }
        while(it2 != nums2.end()){
            nums1.push_back(*it2);
            ++it2;
        }

    }
};

int main(){
    int m(2), n(3);
    int a[10] = {4,5, 6, 7}, b[10] = {4, 11, 22};
    vector<int> nums1(a, a+4), nums2(b, b+3);
    Solution s;
    s.merge(nums1, m, nums2, n);

    vector<int> :: iterator it = nums1.begin();
    for(; it!=nums1.end(); ++it)
        cout << *it  << " ";

    cout << endl;

    return 0;
}
