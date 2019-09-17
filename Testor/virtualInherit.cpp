class A {
public:
	int a;
	virtual void fa(){}
};
class B : virtual public A {
public:
	int b;
	virtual void fa() {}
};


class C : virtual public A {
public:
	int c;

};

class D : public B, public C {
public:
	int d;

};

int main() {
	new D();
}