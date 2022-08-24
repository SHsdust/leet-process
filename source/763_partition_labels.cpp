#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
using namespace std;
// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         int n(s.size());
//         int *last = new int[26];
//         vector<int> result;
//         for(int i=0; i<n; ++i){
//             last[s[i] - 'a'] = i;
//         }

//         int tail(0), begin(0);
//         for(int i=0; i<n; ++i){
//             if(tail < last[s[i] - 'a'])
//                 tail = last[s[i] - 'a'];
//             if(i == tail){
//                 result.push_back(tail - begin + 1);
//                 begin = tail + 1;
//             }
//         }
//         return result;
//     }
// };
class Solution{
 public:
    vector<int> partitionLabels(string s){
        int n(s.size());
        vector<int> last(26, -1), result;
        for(int i=0; i<n; ++i)
            last[s[i] - 'a'] = i;
        int begin(0), tail(0);
        for(int i=0; i<n; ++i){
            if(tail < last[s[i] - 'a'])
                tail = last[s[i] - 'a'];
            if(i==tail){
                result.push_back(tail - begin +1);
                begin = tail + 1;
            }
        }
        return result;
    }
};


int main(){
    int n;
    string s = "vhaagbqkaq";

    Solution sol;
    vector<int> result = sol.partitionLabels(s);
    // vector<int> :: iterator it = result.begin();
    n = result.size();

    cout << "[";
    for(int i=0; i<n; ++i){
        cout << result[i];
        if(i != n-1)
            cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
