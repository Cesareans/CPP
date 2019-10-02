#include "header/static.hpp"

int main(){
    i();
    f();

    for(int i = 0 ; i < 10 ; ++i){
        static int j = 0;
        ++j;
        printf("%d\n", j);
    }

    return 0;
}