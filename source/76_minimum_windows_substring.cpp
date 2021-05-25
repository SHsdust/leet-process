#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
using namespace std;

class Solution{
public:
    string minWindow(string s, string t){
        int n(s.size()), m(t.size());

        vector<int> chars(128, 0);
        vector<int> flags(128, 0);

        for(auto c : t){
            ++chars[c];
            flags[c] = true;
        }

        int l(0), min_l(0), min_size(n+1), cnt(0);

        for(int r=0; r<n; ++r){
            if(flags[s[r]])
                if(--chars[s[r]] >= 0)
                    ++cnt;
            while(cnt == m){
                if(r-l+1 < min_size){
                    min_l = l;
                    min_size = r - l + 1;
                }
                if(flags[s[l]] && ++chars[s[l]]>0)
                    --cnt;
                ++l;
            }
        }
        if(min_size > n)
            return "";
        return s.substr(min_l, min_size);
    }
};

// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int n(s.size()), m(t.size());

//         vector<bool> flags(128, false);
//         vector<int> chars(128, 0);

//         for(auto c : t){
//             flags[c] = true;
//             ++chars[c];
//         }

//         int l(0), min_size(n+1), cnt(0), min_l(0);
//         for(int r=0; r<n; ++r){
//             if(flags[s[r]])
//                 if(--chars[s[r]] >= 0)
//                     ++cnt;

//             while(cnt == m){
//                 if(r-l+1 < min_size){
//                     min_size = r - l + 1;
//                     min_l = l;
//                 }

//                 if(flags[s[l]] && ++chars[s[l]] >0)
//                     --cnt;

//                 ++l;
//             }
//         }

//         cout << min_size << endl;
//         return min_size>n ? "" : s.substr(min_l, min_size);

//     }
// };

int main(){
    string s1, s2;
    while(cin >> s1){
        cin >> s2;

        Solution s;
        cout << s.minWindow(s1, s2) << endl;
    }
    return 0;
}
