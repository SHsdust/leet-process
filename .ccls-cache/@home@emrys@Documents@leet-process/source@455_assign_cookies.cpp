 #include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res(0);
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        vector<int> :: iterator itg = g.begin();
        vector<int> :: iterator its = s.begin();

        while(itg!=g.end() && its!=s.end()){
            if(*its >= *itg){
                its++;
                itg++;
                res++;
            }
            else
                its++;
        }

        return res;
    }
};


int main(){
    int  gree[10] = { 10, 9, 8, 7}, coo[10] = { 5, 6, 7, 8};
    vector<int> g(gree, gree+4), s(coo, coo+4);

    vector<int> :: iterator itg = g.begin();
    vector<int> ::iterator its = s.begin();

    Solution sol;
    cout << sol.findContentChildren(g, s) << endl;
    return 0;
}
