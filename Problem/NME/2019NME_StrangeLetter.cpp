#include <iostream>
#include <string>
using namespace std;
const int N = 128;

int wt[N];

int main() {
    for (int i = 'a'; i <= 'z'; ++i) cin >> wt[i];
    string s;
    cin >> s;
    int width = 0, line = 1;
    for(char c : s){
        if(width + wt[c] > 100){
            width = wt[c];
            ++line;
        }else{
            width += wt[c];
        }

    }
    cout << line << " " << width << endl;
    return 0;
}