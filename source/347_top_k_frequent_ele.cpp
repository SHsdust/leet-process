#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int> freq;
        int max_count(0);
        for(const int num : nums)
            max_count = max(max_count, ++freq[num]);

        vector<vector<int>> buckets(max_count+1);
        for(const auto p : freq)
            buckets[p.second].push_back(p.first);

        vector<int> ans;
        for(int i=max_count; i>=0 && ans.size()<k; --i)
            for(const int p : buckets[i]){
                ans.push_back(p);
                if(ans.size()==k)
                    break;
            }
        return ans;
    }
};

int main(){
    int arr[] = {1,1,1,2,2,3}, k=2;
    vector<int> nums(arr, arr+6);

    Solution s;
    vector<int> result = s.topKFrequent(nums, k);
    for(int i=0; i<result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
