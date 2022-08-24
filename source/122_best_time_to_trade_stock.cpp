#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n(prices.size());
        int profit(0);
        int low(prices[0]), high(prices[0]);

        for(int i=0; i<n; ++i){
            cout << profit << endl;
            if(prices[i] <= low){
                profit += high - low;
                low = prices[i];
                high = prices[i];
                continue;
            }
            if(prices[i] > high)
                high = prices[i];
            else{
                profit += high - low;
                low = prices[i];
                high = prices[i];
            }
        }
        if(high > low)
            profit += high - low;
        return profit;
    }
};


int main(){
    int p[10] = { 2,7,2,4,2,5,4,7,3,5 };
    vector<int> price(p, p+10);

    Solution s;
    cout << s.maxProfit(price) << endl;
    return 0;
}
