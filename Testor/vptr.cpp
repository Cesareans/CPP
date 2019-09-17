#include <iostream>
#include <typeinfo>
using namespace std;
class A {
public:
	virtual void ai() {
		cout << "a.ai" << endl;
	}
	virtual void bi() {
		cout << "a.bi" << endl;
	}
};
class B : public A {
public:
	virtual void bi() {
		cout << "b.bi" << endl;
	}
};
int main()
{
	printf("%p\n", &A::ai);
	// int* ： 将对象视为int数组，每个值为指针
	// *(int*)：解对象引用，取对象中的第一个元素-虚函数表首地址
	// (int*)*(int*) ：将虚函数表首地址视为int数组，每个值为指针，此时+1+2为改变指针指向，切换调用的虚函数
	// *(int*)*(int*)：解对象引用，取虚函数表的第一个元素-第一个虚函数地址
	// (vFun)*(int*)*(int*)：将第一个虚函数地址强转为typedef void(*vFun)() => 第一个虚函数的函数指针
	// 同理 (vFun)*((int*)*(int*)a + 1) => 第二个虚函数的函数指针
	typedef void(*vFun)();
	A *a = new B();
	vFun vf = (vFun)*(int*)*(int*)a;
	vf();
	vf = (vFun)*((int*)*(int*)a + 1);
	vf();
	vf = (vFun) * *(int**)a;
	vf();
	vf = (vFun) * (*(int**)a + 1);
	vf();
	return 0;
}