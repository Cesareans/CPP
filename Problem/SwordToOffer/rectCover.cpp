#include <iostream>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
        int * n = new int[number + 1]();
        n[1] = 1;
        n[2] = 2;
        return rectCover(n, number);
    }
private:
    int rectCover(int* arr, int n){
        if(n!=0 && arr[n] == 0){
            arr[n] = rectCover(arr, n-1)+rectCover(arr, n-2);
        }
        return arr[n];
    }
};

int main(){
    cout<<Solution().rectCover(4);
    return 0;
}