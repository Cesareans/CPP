class Edge{
public:
    int wgt;
    int next;
    int to;
};
const int M = 100010;
Edge edges[M];
int head[M];
int cnt = 0;
void add(int u, int v, int w){
    edges[cnt].wgt = w;
    edges[cnt].to = v;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}