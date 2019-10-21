class A{
public:
    static int i;
    int c = 0;
    mutable int d = 10;

    virtual void func()const{
        i = 10;
        d = 10;
    }
};
int A::i = 1;