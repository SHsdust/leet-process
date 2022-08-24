#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> comb(k, 0);
        int count = 0;
        backtracking(result, comb, count, 1, n, k);
        return result;
    }

    void backtracking(vector<vector<int>> &result, vector<int>& comb, int &count, int pos, int n, int k){
        if (count == k) {
            result.push_back(comb);
            return;
        }
        for (int i = pos; i <= n; ++i) {
            comb[count++] = i;
            backtracking(result, comb, count, i + 1, n, k);
            --count;
        }
    }
};
int main(){
    int n(4), k(2);

    Solution s;
    vector<vector<int>> result = s.combine(n, k);
    cout << "[" << endl;
    for(auto i : result){
        cout << "[";
        for(auto j : i)
            cout << j << ',';
        cout << "], " << endl;
    }
    cout << "]" << endl;

    return 0;
}
