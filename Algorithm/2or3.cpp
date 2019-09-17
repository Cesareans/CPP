//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//
//void climbStairs(const int i, const int n, vector<vector<int>>& res, vector<int>& path) {
//	path.push_back(i);
//	if (i == n) {
//		res.emplace_back(path);
//	}
//	else if (i < n) {
//		climbStairs(i + 2, n, res, path);
//		climbStairs(i + 3, n, res, path);
//	}
//	path.pop_back();
//}
//
//int main() {
//	int n = 0;
//	cin >> n;
//	vector<vector<int>> res;
//	vector<int> path;
//	climbStairs(0, n, res, path);
//	for (const auto& v : res)
//	{
//		for (auto j : v)
//		{
//			cout << j << ", ";
//		}
//		cout << endl;
//	}
//	return 0;
//}