class Arc{
public:
    int wgt;
    int to;
    Arc* next;

    Arc():wgt(0),to(0),next(nullptr) {}
    Arc(int wgt, int to, Arc *next) : wgt(wgt), to(to), next(next) {}
};
const int N = 100010;
Arc arcs[N];
void add(int u, int v, int w){
    Arc * arc = new Arc(w, v, arcs[u].next);
    arcs[u].next = arc;
}