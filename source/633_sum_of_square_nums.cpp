#include "iostream"
#include "cmath"
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int s(sqrt(c));
        for(int i=0; i<=s; ++i){
            int64_t tmp = c - pow(i,2);
            if(pow(size_t(sqrt(tmp)), 2) == tmp)
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
