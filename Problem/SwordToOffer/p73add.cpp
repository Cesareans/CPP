#include <iostream>

using namespace std;

class Solution {
public:
    int add(int num1, int num2) {
        while (num2) {
            num1 = num1 ^ num2;
            num2 = ((num1 ^ num2) & num2) << 1;
        }
        return num1;
    }
};

int main() {
    cout << Solution().add(1, 4);
}