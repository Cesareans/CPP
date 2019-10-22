#include <unordered_set>
using namespace std;

class Solution
{
public:
    unordered_set<char> map;
    void Insert(char ch)
    {
        if(map.find(ch) != map.end()){
            map.erase(ch);
        }else{
            map.insert(ch);
        }
    }
    char FirstAppearingOnce()
    {

    }

};