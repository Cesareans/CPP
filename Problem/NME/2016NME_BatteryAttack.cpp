/*
 * 2016网易互娱：	炮台攻击
 * Easy - 简单模拟题
 */


#include <iostream>

using namespace std;

int main() {
    int r = 0, *x = new int[3], *y = new int[3], x0, y0;
    cin >> r;
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }
    cin >> x0 >> y0;
    int c = 0, R = r * r;
    for (int i = 0; i < 3; ++i) {
        if(R >= (x[i]-x0)*(x[i]-x0) + (y[i]-y0)*(y[i]-y0)){
            c++;
        }
    }
    cout<<c<<"x"<<endl;
    return 0;
}