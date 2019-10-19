#include "header/static.hpp"

class A{
public:
    static int i;
    static int func(){
        return 2;
    }
    int func2(){
        return 3;
    }
};
int A::i = 1;
using ull = unsigned long long;

int main(){
    i();
    f();

    printf("k = %d\n", k);
    printf("A::i = %d\n", A::i);
    printf("A::func() = %d\n", A::func());
    for(int i = 0 ; i < 10 ; ++i){
        static int j = 0;
        ++j;
        printf("%d\n", j);
    }

    return 0;
}