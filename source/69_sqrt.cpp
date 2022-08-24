#include "iostream"
#include "cmath"
#include "cstdlib"
using namespace std;

// quick solution
// class Solution {
// public:
//     int mySqrt(int x) {
//         return sqrt(x);
//     }
// };

// class Solution{
// public:
//     int mySqrt(int x){
//         // "0" is specialized;

//         size_t l(1), r(x), mid;
//         while(l <= r){
//             // overflow in case 1+2147483647
//             mid = (l + r) / 2;

//             // mid = l + (r-l)/2;

//             // overflow if take (mul == x)
//             size_t sqrt(x / mid);

//             if(sqrt == mid)
//                 return mid;
//             else if(sqrt > mid)
//                 l = mid+1;
//             else
//                 r = mid-1;
//         }
//         return r;
//     }
// };


// Newton's method
class Solution{
public:
    int mySqrt(int x){
        size_t a(x);
        while(a*a>x)
            a = (pow(a,2)+x) / (2*a);
        return a;
    }
};


int main(){
    int n ;
    while(cin >> n){
        Solution s;
        cout << s.mySqrt(n) << endl;
    }
    return 0;
}
