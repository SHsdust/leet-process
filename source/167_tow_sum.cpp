#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int tmp;
        vector<int> res;
        vector<int> :: iterator its = numbers.begin();
        vector<int> :: iterator ite = numbers.end() - 1;
        cout << *its << ", " << *ite << endl;
        cout << its-numbers.begin() << ", " << ite-numbers.begin() << endl;
        while(its != ite){
            tmp = *its + *ite;
            if(tmp == target){
                res.push_back(its - numbers.begin() + 1);
                res.push_back(ite - numbers.begin() + 1);
                // cout << *its << ", " << *ite << endl;
                break;
            }
            else if(tmp < target)
                ++its;
            else
                --ite;
        }
        return res;
    }
};

int main(){
    vector<int> inp;
    int in[5]={2, 3}, tar(5);
    for(int i=0; i<2; ++i)
        inp.push_back(in[i]);
    sort(inp.begin(), inp.end());

    Solution s;
    vector<int> res = s.twoSum(inp, tar);
    sort(res.begin(), res.end());
    cout << res[0]  << ", " << res[1] << endl;

    return 0;
}
