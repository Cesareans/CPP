#include "header/base.h"
#include <vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int i = 0, j = array.size()-1;
        while (i<j){
            while (array[i] % 2 == 1 && i < j) ++i;
            while(array[j] % 2 ==0) --j;
            if(i<j) swap(array[i++], array[j--]);
        }
    }
};

int main(){
    vector<int> vec = {1,2,3,4,5};
    Solution().reOrderArray(vec);
    cout<<(vec);
    return 0;
}