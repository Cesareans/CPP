#include <string>
#include <iostream>
using namespace std;

int main(){
    int n;
    string t;
    cin >> n;
    while(n--){
        cin >> t;
        if((t[0] == '2' && t[1] >= '4') || t[0] > '2'){
            t[0] = '0';
        }
        if(t[3] >= '6'){
            t[3] = '0';
        }
        if(t[6] >= '6'){
            t[6] = '0';
        }
        cout << t << endl;
    }
    return 0;
}