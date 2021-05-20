#include "iostream"
#include "cmath"
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int64_t s(sqrt(c));
        // cout << s << endl;
        int64_t sum(0);
        for(int i=0; i<=s; ++i){
            int64_t tmp = c - pow(i,2);
            if(tmp == int(sqrt(tmp)))
                return true;
        }
        return false;
    }
};


int main(){
    int c;
    while(true){
        cin >> c;

        Solution s;
        cout << s.judgeSquareSum(c) << endl;
    }

    return 0;
}
