#include <stdio.h>


class A {
public:
	int a;
	virtual void foo() { printf("A::foo(): this = 0x%p\n", this); }
};
class B {
public:
	int b;
	virtual void bar() { printf("B::bar(): this = 0x%p\n", this); }
};
class C : public A, public B {
public:
	int c;
	virtual void quz() { printf("C::quz(): this = 0x%p\n", this); }
};

void (A::* pafoo)() = &A::foo;   // ptr: 1, adj: 0
void (B::* pbbar)() = &B::bar;   // ptr: 1, adj: 0
void (C::* pcfoo)() = &C::foo;   // ptr: 1, adj: 0
void (C::* pcquz)() = &C::quz;   // ptr: 9, adj: 0
void (C::* pcbar)() = &C::bar;   // ptr: 1, adj: 8

#define PART1_OF_PTR(p)     (((long*)&p)[0])
#define PART2_OF_PTR(p)     (((long*)&p)[1])

int main() {
	A* a = new A();
	printf("%d %d\n", sizeof(&A::foo), sizeof(long*));
	printf("&A::vptr: 0x%X\n", *(int*)a);
	printf("&A::foo->ptr: 0x%lX, ", PART1_OF_PTR(pafoo));   // 1
	printf("&A::foo->adj: 0x%lX\n", PART2_OF_PTR(pafoo));   // 0
	printf("&B::bar->ptr: 0x%lX, ", PART1_OF_PTR(pbbar));   // 1
	printf("&B::bar->adj: 0x%lX\n", PART2_OF_PTR(pbbar));   // 0
	printf("&C::foo->ptr: 0x%lX, ", PART1_OF_PTR(pcfoo));   // 1
	printf("&C::foo->adj: 0x%lX\n", PART2_OF_PTR(pcfoo));   // 0
	printf("&C::quz->ptr: 0x%lX, ", PART1_OF_PTR(pcquz));   // 9
	printf("&C::quz->adj: 0x%lX\n", PART2_OF_PTR(pcquz));   // 0
	printf("&C::bar->ptr: 0x%lX, ", PART1_OF_PTR(pcbar));   // 1
	printf("&C::bar->adj: 0x%lX\n", PART2_OF_PTR(pcbar));   // 8
	(new A())->foo();
	(new B())->bar();
	(new C())->quz();
	return 0;
}