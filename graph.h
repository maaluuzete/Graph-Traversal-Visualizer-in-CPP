#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
using namespace std;

struct node{
    int id;
    float x,y;
};

struct edge{
    int u,v;
};

class graph{
public:
    void add_node(float x,float y);
    void add_edge(int u,int v);
    vector<int> bfs(int s);
    vector<int> dfs(int s);
    const vector<node>& nodes() const;
    const vector<edge>& edges() const;
    void clear();
    void save(const char* f);
    void load(const char* f);

private:
    vector<node> ns;
    vector<edge> es;
    void dfs_go(int v,vector<int>& vis,vector<int>& ord);
};

#endif
