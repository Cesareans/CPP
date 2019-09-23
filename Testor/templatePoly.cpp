#include <iostream>
using namespace std;

template<class derive>
class base
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

class der :public base<der>
{
public:
	der(int foo) :_foo(foo) {}
	static void print()
	{
		cout << "in der print" << endl;
	};
	void m_print()
	{
		cout << "in der member fun m_print" << endl;
		cout << "has member foo=" << _foo << endl;
	}
private:
	int _foo;
};

template<class base>
class der2 :public base
{
public:
	static void print()
	{
		cout << "in der2 print" << endl;
	};
	void m_print()
	{
		cout << "in der2 member fun m_print" << endl;
	}
};

class tmpclass
{
public:
	void test()
	{
		cout << "in test" << endl;
	}
};

int main(int argc, char* argv[])
{
	base<der>* pb = new der(100);
	pb->print();
	pb->m_print();

	der2<tmpclass> d2;
	d2.print();
	d2.m_print();
	d2.test();

	return 0;
}