class WithExplicit{
public:
    explicit WithExplicit(int n){
        this->n = n;
    }

    explicit WithExplicit(int n, int a){
        this->n = n+a;
    }

private:
    int n;
};

class WithoutExplicit{
public:
    WithoutExplicit(int n){
        this->n = n;
    }

private:
    int n;
};

int main(){
    WithoutExplicit withoutExplicit = 1;

    // compile wrong
    // WithExplicit withExplicit = 2;
}