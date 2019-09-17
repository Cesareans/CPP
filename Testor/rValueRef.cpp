#include <cstdio>
#include <iostream>
using namespace std;
class A
{
public:
	A(){
		cout << "Construct A" << endl;
	}
	A(const A& a){
		cout << "Copy construct A" << endl;
	}
	A(A&& a) {
		cout << "Transfer construct A" << endl;
	}
};

A getA()
{
	A a = A();
	return a;
}

A&& getRRefA()
{
	A a = A();
	return move(a);
}

int main()
{
	int i = 0;
	int& li = i; // 左值引用
	int&& ri = 0; // 右值引用

	printf("%d\n", ri);
	ri = 1;
	printf("%d\n", ri);
	printf("%p\n", &li);
	printf("%p\n", &ri);

	const int& j = 9; // 常量引用
	// int& j = 9; = wrong
	
	cout << endl;
	A a;
	cout << endl;
	A a1(a);
	cout << endl;

	cout << "Get A\n";
	A a2 = getA();
	cout << endl;
	A&& a3 = getA();
	cout << endl;

	cout << "Get r ref A\n";
	A a4 = getRRefA();
	cout << endl;
	A&& a5 = getRRefA();
	cout << endl;

	return 0;
}