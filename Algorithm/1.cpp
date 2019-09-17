#include <iostream>
#include <string>
#include <algorithm>
#define m 5000
using namespace std;
int dis[m][m] = {0};
string s, k;
int dist(int i, int j)
{
	return abs((s[i - 1] - 'a') - (k[j - 1] - 'a'));
}
int main()
{
	cin >> s >> k;
	int t;
	cin >> t;
	int len = s.size()>k.size()?s.size():k.size();
	for (int i = 1; i <= s.size(); i++) dis[i][0] = t * i;
	for (int i = 1; i <= k.size(); i++) dis[0][i] = t * i;
	for (int i = 1; i <= s.size(); i++)
	{
		for (int j = 1; j <= k.size(); j++)
		{
			dis[i][j] = min(dis[i - 1][j - 1] + dist(i, j), min(dis[i - 1][j] + t, dis[i][j - 1] + t));
		}
	}
	cout << dis[s.size()][k.size()] << endl;
	return 0;

}