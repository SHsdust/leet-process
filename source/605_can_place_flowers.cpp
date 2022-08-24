#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int remains(n), si(flowerbed.size());
        if(!n)
            return true;
        if(si==1){
            if(!flowerbed[0])
                return true;
            return false;
        }
        if(si == 2){
            if(flowerbed[0]==1 || flowerbed[1]==1)
                return false;
            else if(n==1)
                return true;
            return false;
        }
        for(int i=0; i<si; ++i){
            if(!flowerbed[i]){
                if(i==0){
                    if(!flowerbed[i+1]){
                        --remains;
                        flowerbed[i] = 1;
                    }
                }
                else if(i==si-1){
                    if(!flowerbed[i-1]){
                        --remains;
                        flowerbed[i] = 1;
                    }
                }
                else{
                    if(!flowerbed[i-1] && !flowerbed[i+1]){
                        --remains;
                        flowerbed[i] = 1;
                    }
                }
            }
            if(!remains)
                return true;
        }

        return false;
    }
};

int main(){
    int a[10] = {0,0,1,0,0}, n(1);
    vector<int> flowerbed(a, a+3);

    Solution s;
    cout << s.canPlaceFlowers(flowerbed, n) << endl;
    return 0;
}
