#include <iostream>
using namespace std;

template<class derive>
class Base
{
public:
	void print()
	{
		derive::print();
	}
	void m_print()
	{
		downcast()->derive::m_print();
	}
protected:
	inline derive* downcast()
	{
		return static_cast<derive*>(this);
	};
	inline const derive* downcast()const
	{
		return static_cast<const derive*>(this);
	};
};

class Der : public Base<Der>
{
public:
	Der(int foo) : _foo(foo) {}
	static void print()
	{
		cout << "in Der print" << endl;
	};
	void m_print()
	{
		cout << "in Der member fun m_print" << endl;
		cout << "has member foo=" << _foo << endl;
	}
private:
	int _foo;
};

template<class base>
class Der2 : public base
{
public:
	static void print()
	{
		cout << "in Der2 print" << endl;
	};
	void m_print()
	{
		cout << "in Der2 member fun m_print" << endl;
	}
};

class TmpClass
{
public:
	void test()
	{
		cout << "in test" << endl;
	}
};

int main(int argc, char* argv[])
{
	Base<Der>* pb = new Der(100);
	pb->print();
	pb->m_print();

	Der2<TmpClass> d2;
	d2.print();
	d2.m_print();
	d2.test();

	return 0;
}