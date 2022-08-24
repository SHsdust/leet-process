#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;


class Solution {
public:
    bool isPalindrome(string s){
        int n(s.size()), m(n/2);
        for(int i=0; i<m; ++i)
            if(s[i] != s[n-i-1])
                return false;

        return true;
    }

    bool validPalindrome(string s) {
        int n(s.size()), m(n/2);
        if(n==1 || n==0 || n==2)
            return true;
        for(int i=0; i<m; ++i)
            if(s[i] != s[n-i-1]){
                if(isPalindrome(s.substr(i, n-2*i-1)) || isPalindrome(s.substr(i+1, n-2*i-1)))
                    return true;
                else
                    return false;
            }
        return true;
    }
};

int main(){
    string str;
    while(cin >> str){
        Solution s;
        cout << s.validPalindrome(str) << endl;
    }
    return 0;
}
