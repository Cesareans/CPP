#include<vector>
#include<iostream>
#include<algorithm>
#define sub(b,c) b-c
using namespace std;
vector<int> topK(vector<int> vec, int k) {
	if (vec.size() <= k) return vec;
	vector<int> res;
	res.reserve(k);
	for (int i = 0; i < k; ++i) res.push_back(vec[i]);
	make_heap(res.begin(), res.end(), greater<int>());
	for (int i = k; i < vec.size(); ++i) {
		if (res[0] < vec[i]) {
			res[0] = vec[i];
			make_heap(res.begin(), res.end(), greater<int>());
		}
	}
	return res;
}
int main() {
	vector<int> numbers = topK(vector<int>{1, 2, 3, 4, 5, 6}, 3);
	for_each(numbers.begin(), numbers.end(), [](int d) {cout << d << ", "; });
	printf("\n%d", 2*sub(3,2)*3);
	return 0;
}