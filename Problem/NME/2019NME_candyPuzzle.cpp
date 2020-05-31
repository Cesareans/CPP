#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec;
    vec.reserve(1000);
    int t;
    while (scanf("%d", &t) && t != -1) {
        vec.push_back(t);
    }

    sort(vec.begin(), vec.end());

    int res = 0;
    int cur = vec[0], curt = 1;
    for (int i = 1; i <= vec.size(); ++i) {
        if (i == vec.size() || cur != vec[i]) {
            res += (curt / (cur + 1)) * (cur + 1) + ((curt%(cur+1)) > 0 ? (cur + 1) : 0);
            cur = vec[i];
            curt = 1;
        } else {
            ++curt;
        }
    }
    cout << res;
    return 0;
}