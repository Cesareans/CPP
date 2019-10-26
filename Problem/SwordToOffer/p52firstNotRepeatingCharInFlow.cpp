#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution{
private:
    queue<char> ls;
    unordered_map<char, int> map;
public:
    void insert(char ch){
        if(++map[ch] <= 1){
            ls.push(ch);
        }
    }
    char firstAppearingOnce(){
        while(!ls.empty() && map[ls.front()] > 1) ls.pop();
        return ls.empty()?'#':ls.front();
    }
};