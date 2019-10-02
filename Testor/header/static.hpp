#include <iostream>

static int i() {
	printf("i");
	return 0;
}

static int a() {
	printf("a");
	return 0;
}

int f(){
    printf("f");
    return 0;
}

typedef int(*intFun)();

struct TStruct {

	intFun s = a;
};