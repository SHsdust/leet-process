#include "iostream"
#include "vector"
#include "cstring"
#include "algorithm"
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int res(0), pos(0), si(ratings.size()), pos2(ratings.size()-1);
        int *assign = new int[si];
        for(int i=0; i<si; ++i)
            assign[i] = 1;

        for(; pos < si-1; ++pos)
            if(ratings[pos] < ratings[pos+1])
                assign[pos+1] = assign[pos] + 1;

        for(; pos2>0; --pos2)
            if(ratings[pos2] < ratings[pos2-1])
                if(assign[pos2] >= assign[pos2-1])
                    assign[pos2-1] = assign[pos2] + 1;

        for(int i=0; i<si; ++i)
            res += assign[i];
        return res;
    }
};



int main(){
    int rat[10] = {1,3,4,5,2};
    vector<int> rating(rat, rat+5);

    Solution s;
    cout << s.candy(rating) << endl;
    return 0;
}
