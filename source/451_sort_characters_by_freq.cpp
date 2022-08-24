#include "iostream"
#include "unordered_map"
#include "algorithm"
#include "vector"
#include "string"
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        int max_count(0);

        for(const char c : s)
            max_count =  max(max_count, ++freq[c]);

        vector<vector<int>> buckets(max_count + 1);
        for(const auto p : freq)
            buckets[p.second].push_back(p.first);

        string ans;
        for(int i=max_count; i>=0; --i)
            for(const auto p : buckets[i]){
                for(int j=0; j<i; ++j)
                    ans.push_back(p);
            }

        return ans;
    }
};



int main(){
    string str = "Aabb";

    Solution s;
    string result = s.frequencySort(str);
    cout << result << endl;
    return 0;
}
