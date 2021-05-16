#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int si(people.size()), n(people.size());
        vector<vector<int>> result;
        vector<int> count;
        vector<vector<int>> :: iterator it = people.begin();

        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] <  b[0])
                return true;
            else if(a[0] == b[0])
                return a[1] < b[1];
            else
                return false;
        });

        for(int i=0; i<si; ++i){
            count.push_back(si-i-1);
            for(int j=0; j<i; ++j)
                if(people[j][0] == people[i][0])
                    count[i] = count[i] + 1;
        }
        vector<int> :: iterator itc = count.begin();

        int pos(0);
        while( it != people.end() )
        {

            if((*it)[1] == ((*itc) - (n-pos-1))){
                result.push_back(*it);

                people.erase(it);
                count.erase(itc);

                it = people.begin();
                itc = count.begin();

                pos = 0;
                --n;
                continue;
            }

            ++itc;
            ++it;
            ++pos;
        }
        return result;
    }
};


int main(){
    int arr[10][10] = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2} };
    vector<vector<int>> people;
    for(int i=0; i<6; ++i){
        people.push_back(vector<int>(arr[i], arr[i]+2));
    }

    Solution s;
    vector<vector<int>> result = s.reconstructQueue(people);
    int n(result.size());
    cout << "[";
    for(int i=0; i<n; ++i){
        cout << " [" << result[i][0] << ", " << result[i][1] << "]";
        if(i!=n-1)
            cout << ",";
    }
    cout << " ]" << endl;
    return 0;
}
