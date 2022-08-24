#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
using namespace std;

class Solution {
public:

    string match(string s, string tar){
        string result;
        int p(0), n(s.size());
        for(auto c : tar){
            while(p < n){
                if(c == s[p]){
                    result.push_back(c);
                    ++p;
                    break;
                }
                ++p;
            }
        }
        return result==tar ? result : "";
    }

    string findLongestWord(string s, vector<string>& dictionary) {

        string result;

        sort(dictionary.begin(), dictionary.end(), [](string &a, string &b){

            int i(0);

            if(a.size() != b.size())
                return a.size() > b.size();
            else{
                for( ; i<a.size(); ++i)
                    if(a[i] == b[i])
                        continue;
                    else
                        break;
            }
            return a[i] < b[i];
        });

        for(auto it=dictionary.begin(); it!=dictionary.end(); ++it){
            result = match(s, *it);
            if(result != "")
                return result;
        }

        return "";

    }
};

int main(){
    string str("abce");
    string arr[10] = { "abe","abc" };
    vector<string> vec;
    for(auto i=0; i<2; ++i)
        vec.push_back(arr[i]);

    Solution s;
    cout << s.findLongestWord(str, vec) << endl;

    return 0;
}
