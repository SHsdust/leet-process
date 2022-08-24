#include "iostream"
#include "vector"
using namespace std;
// DP

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 1);
        if(n<=2) return n;
        for(int i=2; i<=n; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int climbStairs2(int n){
        if(n<=2) return n;
        int pre1{2}, pre2{1}, cur;
        for(int i=3; i<=n; ++i){
            cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};

int main(){
    Solution s;
    cout << s.climbStairs(4) << endl;
    cout << s.climbStairs2(4) << endl;
    return 0;
}
