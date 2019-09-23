#include <cstdio>
#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "Construct A" << endl;
    }

    A(const A &a) {
        cout << "Copy construct A" << endl;
    }

    A(A &&a) noexcept {
        cout << "Transfer construct A" << endl;
    }

    A &operator=(const A &a) {
        cout << "Assign construct A" << endl;
    }

    A &operator=(A &&a) noexcept {
        cout << "Transfer assign A" << endl;
    }

};

A getA() {
    A a = A();
    return a;
}

A getDirectA() {
    return A();
}

A &&getRightValueRefOfA() {
    A a = A();
    return move(a);
}

int main()
{
	int i = 0;
	int& li = i; // 左值引用
	int&& ri = 0; // 右值引用
	// int&& rii = i; 右值引用指向左值
	auto&& lii = i; // 带有引用折叠的自主判断得到左值引用=> int& && = int&

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

    cout << "###Create A\n";
    A();
    cout << endl;
    A ca = A();
    cout << endl;

	cout << "###Get A\n";
	getA();
    cout << endl;
	A a2 = getA();
	cout << endl;
	A&& a3 = getA();
	cout << endl;
    A&& a4 = move(getA());
    cout << endl;

    cout << "###Get Direct A\n";
    A ad1 = getDirectA();
    cout << endl;
    A&& ad2 = getDirectA();
    cout << endl;
    A&& ad3 = move(getDirectA());
    cout << endl;

	cout << "###Get r ref A\n";
	A a5 = getRightValueRefOfA();
	cout << endl;
	A&& a6 = getRightValueRefOfA();
	cout << endl;

	return 0;
}